/**
 * Created by loccs on 6/11/17.
 */
public class Solution {
    public static ListNode removeElementsV0(ListNode head, int val) {
        ListNode newList = null;

        // find the valid head
        while ((null!=head) && (val==head.val)) {
            head = head.next;
        }
        if (null==head) {
            return newList;
        }

        newList = new ListNode(head.val);
        head = head.next;

        ListNode node = newList;
        while (null!=head) {
           if (val!=head.val){
               node.next = new ListNode(head.val);
               node = node.next;
           }
           // forward the head
           head = head.next;
        }

       return newList;
    }
    public static ListNode removeElements(ListNode head, int val) {
        ListNode newList = head;

        // find the valid head
        while ((null!=newList) && (val==newList.val)) {
            newList = newList.next;
        }
        if (null==newList) {
            return null;
        }

        ListNode prev = newList, nextNode = newList.next;
        while (null!=nextNode) {
            if (val==nextNode.val){
                prev.next = nextNode.next;
            }else {
                prev = prev.next;
            }
            // forward the list
            nextNode = nextNode.next;
        }

        return newList;
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
        ListNode node = ln;

        node.next = new ListNode(2);
        node = node.next;
        node.next = new ListNode(6);
        node = node.next;
        node.next = new ListNode(3);
        node = node.next;
        node.next = new ListNode(4);
        node = node.next;
        node.next = new ListNode(5);
        node = node.next;
        node.next = new ListNode(6);

        printLinkedList(ln);

        ListNode newList = removeElements(ln, 6);
        printLinkedList(newList);
    }
}
