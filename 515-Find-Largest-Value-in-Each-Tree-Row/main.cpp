#include <iostream>
#include <vector>
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
    vector<int> largestValues(TreeNode *root) {
        if (!root) { return {}; }

        vector<int> vec_max;
        queue<pair<TreeNode *, int>> bfs;

        bfs.emplace(root, 0);
        while (!bfs.empty()) {
            auto node = bfs.front().first;
            auto level = bfs.front().second;

            if (level >= vec_max.size()) {
                vec_max.push_back(node->val);
            } else {
                if (vec_max[level] < node->val) {
                    vec_max[level] = node->val;
                }
            }

            if (node->left) {
                bfs.emplace(node->left, level + 1);
            }
            if (node->right) {
                bfs.emplace(node->right, level + 1);
            }
            bfs.pop();
        }

        return vec_max;
    }
};

int main() {

    return 0;
}