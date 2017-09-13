#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    static bool hasCycle(ListNode *head) {
        if (NULL == head) {
            return false;
        }

        ListNode *ptr = head->next;
        while ((NULL != head) && (NULL != ptr) && (ptr != head)) {
            head = head->next;
            ptr = ptr->next;
            if (NULL != ptr) {
                ptr = ptr->next;
            }
        }

        return (NULL != head) && (NULL != ptr) && (ptr == head);
    }
};

int main() {
    ListNode nodes[] = {
            ListNode(1),
            ListNode(2)
    };

    nodes[0].next = &nodes[1];
    nodes[1].next = &nodes[0];

    cout << std::boolalpha << Solution::hasCycle(nodes) << endl;


    return 0;
}