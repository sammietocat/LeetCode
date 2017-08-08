/**
 * Created by loccs on 6/12/17.
 */
public class Solution {
    public static int removeDuplicates(int[] nums) {
        if (0==nums.length) {
            return 0;
        }

       int len = 1;
        for (int i = 1; i < nums.length; i++) {
           if (nums[i]!=nums[i-1]) {
               nums[len++] = nums[i];
           }
        }

        return len;
    }

    public static void main(String[] args) {
       int[] nums = {1,1,2};

       int newLen = removeDuplicates(nums);
        System.out.println("newLen = "+newLen);
        for (int i = 0; i < newLen; i++) {
            System.out.print(nums[i]+" ");
        }
        System.out.println();
    }
}
