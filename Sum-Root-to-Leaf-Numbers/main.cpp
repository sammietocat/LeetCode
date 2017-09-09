/**
 * @note can be optimized
 * */
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
    static int sumNumbers(TreeNode *root) {
        int sum = 0;
        if (NULL == root) {
            return sum;
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
                    int tmpSum = 0;
                    for (const auto& v:vvec) {
                        tmpSum = tmpSum*10+ v;
                    }

                    sum+=tmpSum;
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

        return sum;
    }
};

int main() {
    /*
    TreeNode tree[] = {
            TreeNode(5), //0
            TreeNode(4), //1
            TreeNode(11), //2
            TreeNode(7), //3
            TreeNode(2), //4
            TreeNode(8), //5
            TreeNode(13), //6
            TreeNode(4), //7
            TreeNode(5), //8
            TreeNode(1), //9
    };
    // build the tree
    tree[0].left = &tree[1];
    tree[0].right = &tree[5];

    tree[1].left = &tree[2];

    tree[2].left = &tree[3];
    tree[2].right = &tree[4];

    tree[5].left = &tree[6];
    tree[5].right = &tree[7];

    tree[7].left = &tree[8];
    tree[7].right = &tree[9];
     */
    TreeNode tree[] = {TreeNode{1}, TreeNode{2}, TreeNode{3}};
    tree[0].left = &tree[1];
    tree[0].right = &tree[2];

    cout << Solution::sumNumbers(tree) << endl;

    return 0;
}
