/**
 * Created by loccs on 6/11/17.
 */
public class Solution {
    public static ListNode mergeTwoLists(ListNode l1, ListNode l2) {
       ListNode newList;

       if(null==l1){
           newList = l2;
           l2 = (null!=l2 ? l2.next:null);
       }else if(null==l2){
           newList = l1;
           l1 = l1.next;
       }else {
          if (l1.val<l2.val) {
              newList = l1;
              l1 = l1.next;
          }else {
              newList = l2;
              l2 = l2.next;
          }
       }

       ListNode tmp = newList;
       while ((null!=l1) && (null!=l2)) {
          if (l1.val<=l2.val) {
              tmp.next = l1;

              // forward the list
              l1 = l1.next;
              tmp = tmp.next;
          }else {
              tmp.next = l2;

              // forward the list
              l2 = l2.next;
              tmp = tmp.next;
          }
       }

       while (null!=l1) {
           tmp.next = l1;

           // forward the list
           l1 = l1.next;
           tmp = tmp.next;
       }
        while (null!=l2) {
            tmp.next = l2;

            // forward the list
            l2 = l2.next;
            tmp = tmp.next;
        }

       return newList;
    }

    static void printLinkedList(ListNode list) {
        while (null!=list) {
            System.out.print(list.val+"->");
            list = list.next;
        }
        System.out.println();
    }
    public static void main(String[] args) {
        ListNode l1 = new ListNode(1);
        /*
        ListNode node = l1;

        node.next = new ListNode(4);
        node = node.next;
        node.next = new ListNode(7);

        ListNode l2 = new ListNode(2);
        node = l2;

        node.next = new ListNode(3);
        node = node.next;
        node.next = new ListNode(4);
        */
        ListNode l2 = null;

        printLinkedList(l1);
        printLinkedList(l2);

        ListNode newList = mergeTwoLists(l1, l2);
        printLinkedList(newList);
    }
}
