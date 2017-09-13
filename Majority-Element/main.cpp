#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    static int majorityElement(vector<int>& nums) {
        int wanted = 0;
        map<int,int> counter;

        for (const auto &x:nums) {
            ++counter[x];
            if(counter[x]>nums.size()/2) {
                wanted = x;
                break;
            }
        }

        return wanted;
    }
};

int main() {
    vector<int> vec = {1,1,2};

    cout << Solution::majorityElement(vec) << endl;

    return 0;
}