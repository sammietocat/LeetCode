#include <iostream>

using namespace std;

class Solution {
public:
    static int hammingWeight(uint32_t n) {
        int n1 = 0;

        while (0 != n) {
            n1 += (n & 1);
            n >>= 1;
        }

        return n1;
    }
};

int main() {
    uint32_t n{11};

    cout << Solution::hammingWeight(n) << endl;
    return 0;
}