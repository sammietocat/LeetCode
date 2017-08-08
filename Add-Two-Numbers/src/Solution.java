import java.util.List;

/**
 * Created by loccs on 6/11/17.
 */
public class Solution {
   public static ListNode addTwoNumbers(ListNode l1, ListNode l2) {
       ListNode sumNode = new ListNode(-1);
       ListNode digit = sumNode;

       int digitSum=0;
       while((null!=l1) && (null!=l2)) {
          digitSum = l1.val+l2.val+digitSum;

          digit.next = new ListNode(digitSum%10);
          digitSum /=10;

          // forward the node by 1
           digit = digit.next;
          l1 = l1.next;
          l2 = l2.next;
       }

       while(null!=l1) {
           digitSum += l1.val;

           digit.next = new ListNode(digitSum%10);
           digitSum /=10;

           digit = digit.next;
           l1 = l1.next;
       }
       while(null!=l2) {
           digitSum += l2.val;

           digit.next = new ListNode(digitSum%10);
           digitSum /=10;

           digit = digit.next;
           l2 = l2.next;
       }

       if(0!=digitSum) {
            digit.next = new ListNode(digitSum);
       }

       return sumNode.next;
   }

   static void printListNode(ListNode ln) {
      if (null!=ln) {
          System.out.print(ln.val);
          ln = ln.next;
      }

      while(null!=ln) {
          System.out.print(" -> "+ln.val);
          ln = ln.next;
      }
      System.out.println();
   }

   public static void main(String[] args) {
        int[] digits1 = {9,9};//{2,4,3};
       int[] digits2 = {1};//,6,4,1,9};

       ListNode node = null;

       ListNode l1 = new ListNode(0);
       node = l1;
       for (int i=0;i<digits1.length;i++) {
          node.next = new ListNode(digits1[i]);
          node = node.next;
       }
       l1 = l1.next;

       ListNode l2 = new ListNode(0);
       node = l2;
       for (int i=0;i<digits2.length;i++) {
           node.next = new ListNode(digits2[i]);
           node = node.next;
       }
       l2 = l2.next;


       System.out.print("n1 = ");
        printListNode(l1);

       System.out.print("n2 = ");
       printListNode(l2);

       ListNode sumList = addTwoNumbers(l1, l2);
       System.out.print("sum = ");
       printListNode(sumList);
   }
}
