/**
 * Created by loccs on 6/12/17.
 */
public class Solution {
    public static int removeElement(int[] nums, int val) {
       if (0==nums.length) {
           return 0;
       }

       int len = 0;
        for (int i = 0; i < nums.length; i++) {
           if (val!=nums[i]){
               nums[len++] = nums[i];
           }
        }

       return len;
    }

    public static void main(String[] args) {
        int[] nums = {3,2,2,3};
        int val = 1;

        int newLen = removeElement(nums,val);
        System.out.println("newLen = "+newLen);
        for (int i = 0; i < newLen; i++) {
            System.out.print(nums[i]+" ");
        }
        System.out.println();
    }
}
