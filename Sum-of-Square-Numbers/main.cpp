#include <iostream>
#include <cmath>

class Solution {
public:
    static bool judgeSquareSum(int c) {
        for (int a = (int) sqrt(c/2); a >= 0; --a) {
            int b = (int) sqrt(c - a * a);

            if (a * a + b * b == c) {
                std::cout << "a = " << a << ", b = " << b << std::endl;
                return true;
            }
        }

        return false;
    }

};

int main() {
    //std::cout << Solution::judgeSquareSum(100000) << std::endl;
    //std::cout << Solution::judgeSquareSum(100000) << std::endl;
    std::cout << Solution::judgeSquareSum(32) << std::endl;
    std::cout << Solution::judgeSquareSum(2) << std::endl;

    return 0;
}