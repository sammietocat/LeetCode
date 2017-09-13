#include <iostream>
#include <cctype>

using namespace std;

class Solution {
public:
    static bool isPalindrome(string s) {
        for (int i = 0, j = s.size() - 1; i < j; ++i, --j) {
            while ((i < j) && !isalnum(s[i])) {
                ++i;
            }
            while ((j > i) && !isalnum(s[j])) {
                --j;
            }
            if (j <= i) {
                break;
            }

            if (!isEqualIgnoreCase(s[i], s[j])) {
                return false;
            }
        }

        return true;
    }

    static bool isEqualIgnoreCase(const char &c1, const char &c2) {
        if (isdigit(c1) && isdigit(c2)) {
            return c1 == c2;
        } else if (isalpha(c1) && isalpha(c2)) {
            return (c1 == c2) || (c1 + 32 == c2) || (c1 == c2 + 32);
        }

        return false;
    }
};

int main() {
    string strs[] = {
            //"A man, a plan, a canal: Panama",
            //"race a car",
            "0P",
            ".,"
    };

    for (const auto &s:strs) {
        cout << s << " is" << " a palindrome: " << std::boolalpha << Solution::isPalindrome(s) << endl;
    }

    return 0;
}