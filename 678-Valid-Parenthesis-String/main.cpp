#include <iostream>

using namespace std;

class Solution {
public:
    bool checkValidString(string s) {
        return checkValidString(s, 0, 0);
    }

    bool checkValidString(const string &s, const int offset, int stack) {
        if (offset >= s.length()) {
            return (0 == stack);
        }

        if ('(' == s[offset]) {
            return checkValidString(s, offset + 1, stack + 1);
        } else if (')' == s[offset]) {
            return (stack > 0) && checkValidString(s, offset + 1, stack - 1);
        } else if ('*' == s[offset]) {
            // enumerate all 3 possible value of '*'
            // 1. empty string
            // 2. left parenthesis
            // 3. right parenthesis (actually can be pruned away if stack<=0)
            return checkValidString(s, offset + 1, stack) || checkValidString(s, offset + 1, stack + 1) ||
                   checkValidString(s, offset + 1, stack - 1);
        }
    }
};

int main() {
    Solution solu;

    cout << solu.checkValidString("()") << endl;
    cout << solu.checkValidString("(*)") << endl;
    cout << solu.checkValidString("(*))") << endl;
    cout << solu.checkValidString(")(*))") << endl;

    return 0;
}