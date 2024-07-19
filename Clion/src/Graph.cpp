#include "../include/Graph.h"

#include <future>
#include <iostream>
#include <queue>
#include <stdexcept>

Node::Node(int id, std::function<int(std::vector<int>)> func)
    : id(id), func(func), output(0) {}

void Graph::addNode(Node *node) {
    nodes[node->id] = node;
    adjList[node->id] = std::vector<int>();
    inDegree[node->id] = 0;
}

void Graph::addEdge(int from, int to) {
    adjList[from].push_back(to);
    inDegree[to]++;
}

std::vector<int> Graph::topologicalSort() {
    std::vector<int> result;
    std::queue<int> q;

    for(const auto& pair : inDegree) {
        if(pair.second == 0) {
            q.push(pair.first);
        }
    }

    while(!q.empty()) {
        int node = q.front();
        q.pop();
        result.push_back(node);

        for(int neighbor : adjList[node]) {
            if(--inDegree[neighbor] == 0) {
                q.push(neighbor);
            }
        }
    }

    if(result.size() != nodes.size()) {
        throw std::runtime_error("runtime error");
    }

    return result;
}

void Graph::executeNode(Node *node) {
    std::vector<int> input;
    for(int inputId : node->inputs) {
        input.push_back(nodes[inputId]->output);
    }
    node->output = node->func(input);
}

void Graph::executeGraph() {
    std::vector<int> sortedNodes = topologicalSort();
    std::unordered_map<int, std::future<void>> futures;
    std::mutex mtx;
    std::condition_variable cv;
    std::unordered_map<int, bool> done;

    for(const auto& nodeId : sortedNodes) {
        done[nodeId] = false;
    }

    for(int nodeId : sortedNodes) {
        Node* node = nodes[nodeId];

        futures[nodeId] = std::async(std::launch::async, [this,node,&mtx,&cv,&done]() {
            {
                std::vector<int> input;

                for(int inputId : node->inputs) {
                    std::unique_lock<std::mutex> lock(mtx);
                    cv.wait(lock, [&done, inputId]{return done[inputId];});
                    input.push_back(nodes[inputId]->output);
                }

                node->output = node->func(input);
            }

            {
                std::lock_guard<std::mutex> lock(mtx);
                done[node->id] = true;
            }
            cv.notify_all();
        });
    }

    for(auto& future : futures) {
        future.second.get();
    }
}

