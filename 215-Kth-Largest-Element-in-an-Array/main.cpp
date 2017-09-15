#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int findKthLargest(vector<int> &nums, int k) {
        buildMaxHeap(nums);

        while (--k != 0) {
            deleteMax(nums);
            //cout << deleteMax(nums) << endl;
        }

        return deleteMax(nums);
    }

private:
    void buildMaxHeap(vector<int> &nums) {
        for (int i = (nums.size() - 1) / 2; i >= 0; --i) {
            percolateDown(nums, i);
        }
    }

    void percolateDown(vector<int> &nums, int hole) {
        int tmp = nums[hole];

        int child = 2 * hole + 1;
        while (child < nums.size()) {
            // find the smaller child
            if ((nums.size() - 1 > child) && (nums[child] < nums[child + 1])) {
                ++child;
            }
            // check if move the child up
            if (nums[child] > tmp) {
                nums[hole] = nums[child];
                hole = child;
            } else {
                break;
            }
            child = 2 * child + 1;
        }
        nums[hole] = tmp;
    }

    int deleteMax(vector<int> &heap) {
        if (heap.empty()) {
            return 0x3fffffff;
        }

        int max = heap[0];

        heap[0] = heap.back();
        heap.pop_back();
        percolateDown(heap, 0);

        return max;
    }
};

int main() {
    vector<int> nums = {3, 2, 1, 5, 6, 4};
    const int k = 2;
    Solution solu;

    solu.findKthLargest(nums, k);
    /*
    for (const auto &n:nums) {
        cout << n << " ";
    }
    cout << endl;
     */

    return 0;
}