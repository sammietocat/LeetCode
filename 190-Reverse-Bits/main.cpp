#include <iostream>

using namespace std;

class Solution {
public:
    static uint32_t reverseBits(uint32_t n) {
        uint32_t rn = 0;

        for (int i = 0; i < 32; ++i) {
            rn = (rn << 1) | ((n >> i) & 1);
        }

        return rn;
    }
};

int main() {
    const int n = 43261596;

    cout << Solution::reverseBits(n) << endl;
    return 0;
}