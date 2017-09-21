#include <iostream>

class Solution {
public:
    int trailingZeroes(int n) {
        int n0 = 0;

        int factor5 = 5;
        while (n / factor5 > 0) {
            n0 += n / factor5;
            factor5 *= 5;
        }

        return n0;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}