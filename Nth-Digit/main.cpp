#include <iostream>

class Solution {
public:
    static int findNthDigit(int n) {
        if (n < 10) {
            return n;
        }

        const int INTERVALS = 10;
        long intervals[] = {9, 180, 2700, 36000, 450000, (long) 54e5, (long) 63e6, (long) 72e7, (long) 81e8,
                            (long) 90e9};

        int i = -1;
        int offset = 1;
        // find the interval containing the n-th digit
        while ((++i < INTERVALS) && (n > intervals[i])) {
            offset *= 10;
            n -= intervals[i];
        }

        // locate the number containing the digit
        int m = offset + (n - 1) / (i + 1);
        // locate the index of digit within the number from right to left
        int l = i - (n - 1) % (i + 1);

        while (l > 0) {
            m /= 10;
            --l;
        }

        return m % 10;
    }
};

int main() {
    //std::cout << "Hello, World!" << std::endl;
    std::cout << Solution::findNthDigit(11) << std::endl;
    std::cout << Solution::findNthDigit(10) << std::endl;
    std::cout << Solution::findNthDigit(3) << std::endl;

    return 0;
}