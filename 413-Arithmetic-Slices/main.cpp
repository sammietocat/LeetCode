#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    static int numberOfArithmeticSlices(vector<int> &A) {
        if (A.size() < 3) { return 0; }

        int difference{A[1] - A[0]}, start{};
        int num_slices{};
        for (int i = 2; i < A.size(); ++i) {
            if (difference == A[i] - A[i - 1]) {
                num_slices += i - start - 1;
            } else {
                start = i - 1;
                difference = A[i] - A[i - 1];
            }
        }

        return num_slices;
    }
};

int main() {
    vector<int> A{1, 2, 3, 4};

    cout << Solution::numberOfArithmeticSlices(A) << endl;

    return 0;
}