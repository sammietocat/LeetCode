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
    static UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if (!node) { return NULL; }

        unordered_map<int, UndirectedGraphNode *> label_node_maps;
        queue<UndirectedGraphNode *> G;

        int root_label = node->label;
        auto ptr = new UndirectedGraphNode{root_label};

        G.push(node);
        label_node_maps.emplace(root_label, ptr);

        while (!G.empty()) {
            ptr = G.front();
            G.pop();

            //cout << ptr->label << endl;
            for (const auto nb : ptr->neighbors) {
                if (std::end(label_node_maps) == label_node_maps.find(nb->label)) {
                    label_node_maps[nb->label] = new UndirectedGraphNode(nb->label);
                    G.push(nb);
                }
                //cout << "\t" << nb->label << endl;
                ptr->neighbors.push_back(label_node_maps[nb->label]);
            }
        }

        return label_node_maps[root_label];
    }
};

int main() {
    UndirectedGraphNode nodes[] = {
            UndirectedGraphNode{0},
            UndirectedGraphNode{1},
            UndirectedGraphNode{2},
    };

    nodes[0].neighbors.push_back(nodes + 1);
    nodes[0].neighbors.push_back(nodes + 2);

    nodes[1].neighbors.push_back(nodes + 0);
    nodes[1].neighbors.push_back(nodes + 2);

    nodes[2].neighbors.push_back(nodes + 0);
    nodes[2].neighbors.push_back(nodes + 1);
    nodes[2].neighbors.push_back(nodes + 2);

    cout << "address" << endl;
    cout << "\t" << static_cast<void *>(nodes) << endl;
    cout << "\t" << static_cast<void *>(nodes + 1) << endl;
    cout << "\t" << static_cast<void *>(nodes + 2) << endl;
    /*
    for (const auto node : nodes) {
        cout << node.label << endl;
        for (const auto n : node.neighbors) {
            cout << "\t" << n->label << endl;
        }
    }
     */

    auto ptr = Solution::cloneGraph(nodes);
    for (auto nb : ptr->neighbors) {
        cout << nb->label << endl;
        delete nb;
    }
    cout << ptr->label << endl;
    delete ptr;

    return 0;
}