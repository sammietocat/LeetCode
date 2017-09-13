#include <iostream>
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
    TreeNode *sortedArrayToBST(vector<int> &nums) {
        return makeNode(nums, 0, nums.size());
    }

    TreeNode *makeNode(vector<int> &nums, int lo, int hi) {
        if (lo >= hi) {
            return NULL;
        }

        int mid = (lo + hi) / 2;
        TreeNode *node = new TreeNode(nums[mid]);
        node->left = makeNode(nums, lo, mid);
        node->right = makeNode(nums, mid + 1, hi);

        return node;
    }
};

int main() {
    return 0;
}