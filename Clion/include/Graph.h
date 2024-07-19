#ifndef GRAPH_H
#define GRAPH_H
#include <functional>

class Node {
public:
    int id;
    std::function<int(std::vector<int>)> func;
    std::vector<int> inputs;
    int output;

    Node(int id, std::function<int(std::vector<int>)> func);
};

class Graph {
public:
    std::unordered_map<int, Node*> nodes;
    std::unordered_map<int, std::vector<int>> adjList;
    std::unordered_map<int, int> inDegree;

    void addNode(Node* node);
    void addEdge(int from, int to);
    std::vector<int> topologicalSort();
    void executeGraph();

private:
    void executeNode(Node* node);
};

#endif //GRAPH_H
