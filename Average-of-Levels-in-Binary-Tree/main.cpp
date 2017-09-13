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
    static vector<double> levelOrderBottom(TreeNode *root) {
        vector<double> avgs;
        if (NULL == root) {
            return avgs;
        }

        queue<TreeNode *> bfs;
        queue<int> levels;
        vector<int> levelSize;
        TreeNode *cursor;
        int currLevel;

        bfs.push(root);
        levels.push(1);
        while (!bfs.empty()) {
            cursor = bfs.front();
            bfs.pop();
            currLevel = levels.front();
            levels.pop();

            if (avgs.size() < currLevel) {
                avgs.push_back(0);
                levelSize.push_back(0);
            }
            avgs[currLevel - 1] += cursor->val;
            ++levelSize[currLevel - 1];

            // move to next level
            ++currLevel;

            if (NULL != cursor->left) {
                bfs.push(cursor->left);
                levels.push(currLevel);
            }

            if (NULL != cursor->right) {
                bfs.push(cursor->right);
                levels.push(currLevel);
            }
        }

        for (int i = 0; i < avgs.size(); ++i) {
            avgs[i] /= levelSize[i];
        }

        return avgs;
    }
};

int main() {
    TreeNode tree[] = {TreeNode(3), TreeNode(9), TreeNode(20), TreeNode(15), TreeNode(7)};

    tree[0].left = &tree[1];
    tree[0].right = &tree[2];

    tree[2].left = &tree[3];
    tree[2].right = &tree[4];

    const auto avgs = Solution::levelOrderBottom(tree);

    cout << "[";
    for (const auto &cell:avgs) {
        cout << cell << ",";
    }
    cout << "]," << endl;

    return 0;
}
