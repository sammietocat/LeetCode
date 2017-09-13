#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    bool isBalanced(TreeNode *root) {
        return (-1 != calcDepthByDFS(root));
    }

    int calcDepthByDFS(const TreeNode *root) {
        if (NULL == root) {
            return 0;
        }

        int l = calcDepthByDFS(root->left);
        if (-1 == l) {
            return -1;
        }

        int r = calcDepthByDFS(root->right);
        if (-1 == r) {
            return -1;
        }

        if (abs(l - r) > 1) {
            return -1;
        }

        return max(l, r) + 1;
    }
};

int main(int argc, char *argv[]) {


    return 0;
}
