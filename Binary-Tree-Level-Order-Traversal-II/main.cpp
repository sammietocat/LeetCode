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
    static vector<vector<int>> levelOrderBottom(TreeNode *root) {
        vector<vector<int>> vec;
        if (NULL == root) {
            return vec;
        }

        queue<TreeNode *> bfs;
        queue<int> levels;
        TreeNode *cursor;
        int currLevel;

        bfs.push(root);
        levels.push(1);
        while (!bfs.empty()) {
            cursor = bfs.front();
            bfs.pop();
            currLevel = levels.front();
            levels.pop();

            if (vec.size() < currLevel) {
                vec.push_back(vector<int>{});
            }
            vec[currLevel-1].push_back(cursor->val);

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

        for (int i = 0, j = vec.size() - 1; i < j; ++i, --j) {
            vec[i].swap(vec[j]);
        }

        return vec;
    }
};

int main() {
    TreeNode tree[] = {TreeNode(3), TreeNode(9), TreeNode(20), TreeNode(15), TreeNode(7)};

    tree[0].left = &tree[1];
    tree[0].right = &tree[2];

    tree[2].left = &tree[3];
    tree[2].right = &tree[4];

    const auto vec = Solution::levelOrderBottom(tree);

    for (const auto &row:vec) {
        cout << "[";
        for (const auto &cell:row) {
            cout << cell << ",";
        }
        cout << "]," << endl;
    }

    return 0;
}