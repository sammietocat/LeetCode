#include <iostream>
#include <queue>

using namespace std;

class Solution {
public:
    // v1: lower space, but slower?
    static int countArrangement(int N) {
        deque<int> nums_left;
        for (int i = 1; i <= N; ++i) {
            nums_left.emplace_back(i);
        }

        int num_perfect{};
        nextNum(num_perfect, N, 1, nums_left);

        return num_perfect;
    }

    static void nextNum(int &num_perfect, const int N, const int level, deque<int> &nums_left) {
        if (level == N) {
            num_perfect += (((0 == N % nums_left.back()) || (0 == nums_left.back() % N)) ? 1 : 0);
        }

        // # of elements left to consider
        int nums_size = nums_left.size();

        int tmp;
        while (--nums_size >= 0) {
            tmp = nums_left.back();
            nums_left.pop_back();

            if ((0 == tmp % level) || (0 == level % tmp)) {
                // advance into next level
                nextNum(num_perfect, N, level + 1, nums_left);
            }

            // backtrack by adding back the removed element
            nums_left.emplace_front(tmp);
        }
    }

    // v0
    /*
    static int countArrangement(int N) {
        deque<int> nums_left;
        for (int i = 1; i <= N; ++i) {
            nums_left.emplace_back(i);
        }

        return nextNum(N, 1, nums_left);
    }

    static int nextNum(const int N, const int level, deque<int> &nums_left) {
        if (level == N) {
            return ((0 == N % nums_left.back()) || (0 == nums_left.back() % N)) ? 1 : 0;
        }

        // # of perfect arrangements detected in this level
        int num_perfect{};
        // # of elements left to consider
        int nums_size = nums_left.size();

        int tmp;
        while (--nums_size >= 0) {
            tmp = nums_left.back();
            nums_left.pop_back();

            if ((0 == tmp % level) || (0 == level % tmp)) {
                // advance into next level
                num_perfect += nextNum(N, level + 1, nums_left);
            }

            // backtrack by adding back the removed element
            nums_left.emplace_front(tmp);
        }

        return num_perfect;
    }
     */
};

int main() {
    for (int N = 1; N <= 15; ++N) {
        cout << N << ": " << Solution::countArrangement(N) << endl;
    }

    return 0;
}