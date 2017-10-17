#include <iostream>
#include <queue>

using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    static vector<int> rightSideView(TreeNode *root) {
        if (NULL == root) { return {}; }

        queue<pair<TreeNode *, int>> bfs;
        vector<int> views;

        bfs.emplace(root, 0);
        while (!bfs.empty()) {
            auto node = bfs.front().first;
            auto level = bfs.front().second;
            bfs.pop();

            if (level >= views.size()) {
                views.emplace_back(node->val);
            }

            if (node->right) {
                bfs.emplace(node->right, level + 1);
            }
            if (node->left) {
                bfs.emplace(node->left, level + 1);
            }
        }

        return views;
    }
};

int main() {
    TreeNode nodes[] = {
            TreeNode{1},
            TreeNode{2},
            TreeNode{3},
            TreeNode{4},
            TreeNode{5},
            TreeNode{6},
    };

    nodes[0].left = nodes + 1;
    nodes[0].right = nodes + 2;

    nodes[1].right = nodes + 4;

    nodes[2].right = nodes + 3;

    nodes[4].left = nodes + 5;

    auto view = Solution::rightSideView(nodes);
    for (const auto &v : view) {
        cout << v << " ";
    }
    cout << endl;

    return 0;
}