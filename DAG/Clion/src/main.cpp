#include "../include/Graph.h"
#include <iostream>

int add(const std::vector<int>& input) {
    return input[0] + input[1];
}

int square(const std::vector<int>& input) {
    return input[0] * input[0];
}

int find_max(const std::vector<int>& input) {
    return *std::max_element(input.begin(), input.end());
}

int main() {
    // 테스트
    Graph g;

    Node* node1 = new Node(1, add);
    node1->inputs = {2,3};
    g.addNode(node1);

    Node* node2 = new Node(2, square);
    node2->inputs = {4};
    g.addNode(node2);

    Node* node3 = new Node(3, find_max);
    node3->inputs = {5,6};
    g.addNode(node3);

    Node* node4 = new Node(4, [](const std::vector<int>& input){return 5;});
    g.addNode(node4);

    Node* node5 = new Node(5, [](const std::vector<int>& input){return 2;});
    g.addNode(node5);

    Node* node6 = new Node(6, [](const std::vector<int>& input){return 3;});
    g.addNode(node6);
 
    g.addEdge(2, 1);
    g.addEdge(3, 1);
    g.addEdge(4, 2);
    g.addEdge(5, 3);
    g.addEdge(6, 3);

    g.executeGraph();

    for(const auto& pair : g.nodes) {
        std::cout << "Node " << pair.first << " output : " << pair.second->output << std::endl;
    }

    for(const auto& pair : g.nodes) {
        delete pair.second;
    }

    return 0;
}
