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
    int findBottomLeftValue(TreeNode *root) {
        queue<TreeNode *> bfs;

        TreeNode *left_most_leaf = NULL;
        bfs.emplace(root);
        while (!bfs.empty()) {
            auto ptr = bfs.front();

            if (ptr->right) {
                bfs.emplace(ptr->right);
            }
            if (ptr->left) {
                bfs.emplace(ptr->left);
            }

            left_most_leaf = ptr;
            bfs.pop();
        }

        return left_most_leaf->val;
    }
};

int main() {
    return 0;
}