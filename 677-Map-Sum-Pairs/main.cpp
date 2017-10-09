#include <iostream>
#include <stack>
#include <vector>

using namespace std;

class MapSum {
public:
    struct Trie {
        char id;
        int value;
        bool is_word_end;
        vector<Trie *> children;

        Trie(const char id_ = 0) : id{id_}, value{-1}, is_word_end{false} {}
    };

    /** Initialize your data structure here. */
    MapSum() {
        trie = new Trie;
    }

    void insert(string key, int val) {
        Trie *ptr = trie;
        for (const auto &c:key) {
            bool ok = false;
            for (const auto &child:ptr->children) {
                if (c == child->id) {
                    ptr = child;
                    ok = true;
                    break;
                }
            }

            if (!ok) {
                ptr->children.push_back(new Trie{c});
                //ptr = ptr->children.front();
                ptr = ptr->children.back();
            }
        }

        if (ptr != trie) {
            ptr->value = val;
            ptr->is_word_end = true;
        }
    }

    int sum(string prefix) {
        Trie *ptr = trie;

        bool has_prefix = true;
        for (const char &c:prefix) {
            bool ok = false;
            //cout << "c = " << c << endl;
            for (const auto &child:ptr->children) {
                //cout << "\t" << child->id << endl;
                if (c == child->id) {
                    ptr = child;
                    ok = true;
                    break;
                }
            }

            if (!ok) {
                has_prefix = false;
                break;
            }
        }

        if (!has_prefix) { return 0; }

        stack<Trie *> pairs;
        pairs.push(ptr);
        /*
        for (const auto &child:ptr->children) {
            pairs.push(child);
        }
         */

        int sum_prefix{};
        while (!pairs.empty()) {
            auto pr = pairs.top();
            pairs.pop();

            for (const auto &child:pr->children) {
                pairs.push(child);
            }

            if (pr->is_word_end) {
                sum_prefix += pr->value;
            }
        }

        return sum_prefix;
    }

    ~MapSum() {
        stack<Trie *> node2remove;

        node2remove.push(trie);
        {
            Trie *ptr;
            while (!node2remove.empty()) {
                ptr = node2remove.top();
                node2remove.pop();

                for (auto c:ptr->children) {
                    node2remove.push(c);
                }

                delete ptr;
            }
        }
    }

private:
    Trie *trie{nullptr};
};

int main() {
    MapSum map_sum;

    /*
    map_sum.insert("apple", 3);
    //cout << map_sum.sum("ap") << endl;
    cout << map_sum.sum("apple") << endl;

    map_sum.insert("app", 2);
    cout << map_sum.sum("ap") << endl;
     */

    map_sum.insert("a", 3);
    cout << map_sum.sum("ap") << endl;

    map_sum.insert("b", 2);
    cout << map_sum.sum("a") << endl;

    return 0;
}