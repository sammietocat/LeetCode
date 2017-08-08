/**
 * Created by loccs on 6/11/17.
 */
public class Solution {
    public static boolean isPalindrome(ListNode head) {
       ListNode forward, backward;
       // count # of nodes
        int nodeCnt = 0;
        forward = head;
        while (null!=forward){
            nodeCnt++;
            forward = forward.next;
        }
        System.out.println("nodeCnt = "+nodeCnt);

       // find the middle node(s)
        forward = head;
        backward = null;

        ListNode tmp = null;
        for (int i = 0; i < nodeCnt/2; i++) {
            backward = forward;
            forward = forward.next;
            backward.next = tmp;
            tmp = backward;
        }

        // increment forward node by 1 in case of #(node) is odd
        if (1==nodeCnt%2){
            forward = forward.next;
        }

        /*
        while (null!=backward) {
            System.out.print(backward.val+" -> ");
            backward = backward.next;
        }
        System.out.println();
        while (null!=forward) {
            System.out.print(forward.val+" -> ");
            forward = forward.next;
        }
        System.out.println();
        */
        // forward and backward list must be of equal length
        while ((null!=forward) && (null!=backward)) {
            if (forward.val!=backward.val) {
                return false;
            }
            forward = forward.next;
            backward = backward.next;
        }

       return true;
    }

    static void printLinkedList(ListNode ln) {
        if (null==ln) {
            return ;
        }

        System.out.print(ln.val);
        ln = ln.next;
        while (null!=ln) {
            System.out.print("->"+ln.val);
            ln = ln.next;
        }
        System.out.println();
    }

    public static void main(String[] args) {
       ListNode ln = new ListNode(1);
       ListNode tail = ln;

       tail.next = new ListNode(2);
        tail = tail.next;
       /*
        tail.next = new ListNode(3);
        tail = tail.next;
        tail.next = new ListNode(2);
        tail = tail.next;
        tail.next = new ListNode(1);
        */

        printLinkedList(ln);

        System.out.println(isPalindrome(ln));
    }
}
