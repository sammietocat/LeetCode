/**
 * Created by loccs on 6/11/17.
 */
public class Solution {
    public static ListNode reverseList(ListNode head) {
        ListNode revList, prev, next;

        revList = head;
        prev = null;
        while (null != revList) {
            next = revList.next;
            revList.next = prev;
            prev = revList;
            revList = next;
        }

        return prev;
    }

    static void printLinkedList(ListNode ln) {
        while (null != ln) {
            System.out.print(ln.val + " -> ");
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
        //tail = tail.next;

        printLinkedList(ln);

        ListNode revList = reverseList(ln);
        printLinkedList(revList);
    }
}
