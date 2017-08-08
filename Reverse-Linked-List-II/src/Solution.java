/**
 * Created by loccs on 6/11/17.
 */
public class Solution {
    public static ListNode reverseBetween(ListNode head, int m, int n) {
        ListNode revSubList, prev, next;
        ListNode offset, revSubListTail;

        revSubList = head;
        offset = null;
        for (int i=1;i<m;i++){
            offset = revSubList;
            revSubList = revSubList.next;
        }
        revSubListTail = revSubList;
        if(null!=offset) {
            System.out.println("offset = "+offset.val);
        }
        System.out.println("revSubListTail = "+revSubListTail.val);
        //System.out.println("revSubList = "+revSubList.val);

        prev = null;
        for (int j = m; j <= n; j++) {
           next = revSubList.next;
           revSubList.next = prev;
           prev = revSubList;
           revSubList = next;
        }

        if(null!=offset) {
            offset.next = prev;
        } else {
            head = prev;
        }
        if (null!=revSubListTail) {
            revSubListTail.next = revSubList;
        }

        return head;
    }

    static void printLinkedList(ListNode ln) {
        while (null!=ln) {
            System.out.print(ln.val+" -> ");
            ln = ln.next;
        }
        System.out.println();
    }
    public static void main(String[] args) {
        ListNode ln = new ListNode(1);
        ListNode tail = ln;

        tail.next = new ListNode(2);
        tail = tail.next;
        tail.next = new ListNode(3);
        tail = tail.next;
        tail.next = new ListNode(4);
        tail = tail.next;
        tail.next = new ListNode(5);

        printLinkedList(ln);

        ListNode revList = reverseBetween(ln, 1, 5);
        printLinkedList(revList);
    }
}
