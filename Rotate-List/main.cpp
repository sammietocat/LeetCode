#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    static ListNode *rotateRight(ListNode *head, int k) {
        if (NULL == head) {
            return head;
        }

        // find the length of the list
        int l = 1;
        ListNode *ptr = head, *ptr2 = head->next;
        while (NULL != ptr2) {
            ptr = ptr->next;
            ptr2 = ptr2->next;
            ++l;
        }

        k %= l;
        // make it a cycle temporarily
        ptr->next = head;
        // place ptr at head
        ptr = head;
        // offset ptr2 by k w.r.t ptr
        ptr2 = ptr;
        for (int i = 0; i < k; ++i) {
            ptr2 = ptr2->next;
        }

        while (ptr2->next != head) {
            ptr = ptr->next;
            ptr2 = ptr2->next;
        }

        ptr2 = ptr->next;
        // break the cycle
        ptr->next = NULL;
        return ptr2;
    }
};

int main() {
    const int N = 1;
    ListNode list[] = {
            ListNode(1),
            /*
            ListNode(2),
            ListNode(3),
            ListNode(4),
            ListNode(5),
             */
    };
    for (int i = 0; i < N-1; ++i) {
        list[i].next = &list[i + 1];
    }

    for (ListNode *ptr = list; NULL != ptr; ptr = ptr->next) {
        cout << ptr->val << "->";
    }
    cout << endl;

    ListNode *ptr = Solution::rotateRight(list,2);
    while (NULL!=ptr) {
        cout << ptr->val << "->";
        ptr = ptr->next;
    }


    return 0;
}