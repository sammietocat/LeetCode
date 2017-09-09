#include <iostream>
#include <stack>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    static vector<string> binaryTreePaths(TreeNode *root) {
        vector<string> pathVec;
        if (NULL == root) {
            return pathVec;
        }

        stack<TreeNode *> dfs;
        vector<int> vvec;
        vector<bool> isLeaf;
        TreeNode *node;

        dfs.push(root);
        vvec.push_back(root->val);
        isLeaf.push_back(true);
        while (!dfs.empty()) {
            node = dfs.top();
            if ((NULL == node->left) && (NULL == node->right)) {
                if (isLeaf.back()) {
                    pathVec.push_back("");
                    auto &back = pathVec.back();

                    back += to_string(vvec[0]);
                    for (int i = 1; i < vvec.size(); ++i) {
                        back += "->" + to_string(vvec[i]);
                    }
                }

                dfs.pop();
                vvec.pop_back();
                isLeaf.pop_back();
            } else if (NULL != node->left) {
                isLeaf.back() = false;

                dfs.push(node->left);
                vvec.push_back(dfs.top()->val);
                isLeaf.push_back(true);

                node->left = NULL;
            } else { // node->left is NULL
                isLeaf.back() = false;

                dfs.push(node->right);
                vvec.push_back(dfs.top()->val);
                isLeaf.push_back(true);

                node->right = NULL;
            }

        }

        return pathVec;
    }
};

int main() {
    TreeNode root(1);
    root.left = new TreeNode(2);
    root.right = new TreeNode(3);
    root.left->right = new TreeNode(5);

    for (const auto &p:Solution::binaryTreePaths(&root)) {
        cout << p << endl;
    }

    delete root.left->left;
    delete root.left;
    delete root.right;

    return 0;
}