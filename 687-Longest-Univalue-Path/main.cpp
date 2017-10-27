#include <iostream>

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int longestUnivaluePath(TreeNode *root) {
        int path_longest{};

        if (root) {
            dfs(root, path_longest);
        }

        return path_longest;
    }

private:
    int dfs(TreeNode *root, int &path_longest) {
        // longest branch of starting from left child exclusively
        int branch_left_child = root->left ? dfs(root->left, path_longest) : 0;
        // longest branch of starting from right child exclusively
        int branch_right_child = root->right ? dfs(root->right, path_longest) : 0;

        int branch_left = (root->left && root->val == root->left->val) ? branch_left_child + 1 : 0;
        int branch_right = (root->right && root->val == root->right->val) ? branch_right_child + 1 : 0;

        path_longest = std::max(path_longest, branch_left + branch_right);
        return std::max(branch_left, branch_right);
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}