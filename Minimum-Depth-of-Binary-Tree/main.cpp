#include <iostream>
#include <queue>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int minDepth(TreeNode *root) {
        if (NULL == root) {
            return 0;
        }

        queue<TreeNode *> bfs;
        queue<int> depths;

        TreeNode *tmp;
        int currDepth;

        bfs.push(root);
        depths.push(1);
        while (!bfs.empty()) {
            tmp = bfs.front();
            bfs.pop();

            currDepth = depths.front();
            depths.pop();

            if ((NULL == tmp->left) && (NULL == tmp->right)) {
                return currDepth;
            }

            if (NULL != tmp->left) {
                bfs.push(tmp->left);
                depths.push(currDepth+1);
            }
            if (NULL != tmp->right) {
                bfs.push(tmp->right);
                depths.push(currDepth+1);
            }
        }

        // should never reach here
        return -1;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}