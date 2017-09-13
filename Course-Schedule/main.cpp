#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    static bool canFinish(int numCourses, vector<pair<int, int>> &prerequisites) {
        // 0 or 1 course can be finished
        if (numCourses < 2) {
            return true;
        }

        vector<vector<int>> G{numCourses, vector<int>{}};
        // build the graph
        for (const auto &p:prerequisites) {
            G[p.first].push_back(p.second);
        }

        vector<int> dfsStack;
        vector<bool> isUnvisited(numCourses, 1);
        vector<int> path;
        vector<bool> isInPath;

        dfsStack.reserve(numCourses);
        isInPath.resize(numCourses);

        for (int i = 0; i < isUnvisited.size(); ++i) {
            if (!isUnvisited[i]) {
                continue;
            }

            dfsStack.push_back(i);
            isUnvisited[i] = false;
            // reset path
            path.clear();
            // reset flags indicating whether in path
            for (int j = 0; j < isInPath.size(); ++j) {
                isInPath[j] = false;
            }

            // dive into DFS
            while (!dfsStack.empty()) {
                int idx = dfsStack.back();
                if (!isInPath[idx]) {
                    path.push_back(idx);
                    isInPath[idx] = true;
                }

                // check if all children have been visited
                for (const auto &c:G[idx]) {
                    // check for cycle
                    for (const auto &p:path) {
                        if (c == p) {
                            return false;
                        }
                    }

                    // add on the next unvisited child
                    if (isUnvisited[c]) {
                        dfsStack.push_back(c);
                        isUnvisited[c] = false;
                    }
                }
                // unchanged stack size means all children have been visited
                if (dfsStack.back() == idx) {
                    dfsStack.pop_back();
                    path.pop_back();
                }
            }
        }

        return true;
    }
};

int main() {
    const int numCourses = 4;
    vector<pair<int, int>> prerequisites = {
            /*
            {0, 2},
            {1, 2},
            {2, 0}
             */
            {3, 0},
            {0, 1}
            /*
            {1, 0},
            {2, 6},
            {1, 7},
            {6, 4},
            {7, 0},
            {0, 5}
             */
    };

    cout << std::boolalpha << Solution::canFinish(numCourses, prerequisites) << endl;


    return 0;
}