#include <iostream>
#include <queue>
#include <unordered_map>

using namespace std;

// Definition for undirected graph.
struct UndirectedGraphNode {
    int label;
    vector<UndirectedGraphNode *> neighbors;

    UndirectedGraphNode(int x) : label(x) {};
};

class Solution {
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if (!node) { return NULL; }

        unordered_map<int, UndirectedGraphNode *> label_node_maps;
        queue<UndirectedGraphNode *> G;
        int root_label = node->label;

        G.push(node);
        while (!G.empty()) {
            auto ptr = G.front();
            G.pop();

            if (std::end(label_node_maps) == label_node_maps.find(ptr->label)) {
                label_node_maps.emplace(ptr->label, new UndirectedGraphNode(ptr->label));
            }

            for (const auto &nb : ptr->neighbors) {
                auto itr = label_node_maps.find(nb->label);
                if (std::end(label_node_maps) == itr) {
                    label_node_maps[nb->label] = new UndirectedGraphNode(nb->label);

                    ptr->neighbors.push_back(label_node_maps[nb->label]);
                    //label_node_maps[nb->label]->neighbors.push_back(ptr);

                    G.push(nb);
                } else if (ptr->label != nb->label) {
                    ptr->neighbors.push_back(label_node_maps[nb->label]);
                }
            }
        }

        return label_node_maps[root_label];
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}