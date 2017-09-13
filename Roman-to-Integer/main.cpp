#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    static int romanToInt(string s) {
        int value = 0;

        for (int i = 0; i < s.length();) {
            vector<short> nums;
            short tmp;

            nums.push_back(0);
            for (int j = i; j < s.length(); ++j) {
                tmp = maptoInt(s[j]);
                if(tmp>=nums.back()) {
                    nums.back() *= -1;
                    nums.push_back(tmp);
                }else {
                    i = j;
                    break;
                }

                if((3==nums.size()))
                if((nums.back()==nums[nums.size()-2]))
            }
        }
    }

    static short maptoInt(const char rc) {
        if ('I' == rc) {
            return 1;
        } else if ('V' == rc) {
            return 5;
        } else if ('X' == rc) {
            return 10;
        } else if ('L' == rc) {
            return 50;
        } else if ('C' == rc) {
            return 100;
        } else if ('D' == rc) {
            return 500;
        } else if ('M' == rc) {
            return 1000;
        } else {
            return 0;
        }
    }
};

int main() {

    return 0;
}