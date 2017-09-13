#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    static ListNode* detectCycle(ListNode *head) {
        if (NULL == head) {
            return NULL;
        }

        ListNode *ptr = head->next;
        while ((NULL != head) && (NULL != ptr) && (ptr != head)) {
            head = head->next;
            ptr = ptr->next;
            if (NULL != ptr) {
                ptr = ptr->next;
            }
        }

        if((NULL != head) && (NULL != ptr) && (ptr == head)) {
            // cycle detected
            return head;
        }else {
            // no cycle
            return NULL;
        }
    }
};

int main() {
    ListNode nodes[] = {
            ListNode(1),
            ListNode(2)
    };

    nodes[0].next = &nodes[1];
    nodes[1].next = &nodes[0];

    cout << Solution::detectCycle(nodes) << endl;


    return 0;
}
