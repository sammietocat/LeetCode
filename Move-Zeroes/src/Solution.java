/**
 * Created by loccs on 6/12/17.
 */
public class Solution {
    public static void moveZeros(int[] nums) {
        int len = 0;
        for (int i = 0; i < nums.length; i++) {
           if (0!=nums[i]){
               nums[len++] = nums[i];
           }
        }

        for (int i = len; i < nums.length; i++) {
           nums[i] = 0;
        }
    }

    public static void main(String[] args) {
       int[] nums = {0,1,0,3,12};

       moveZeros(nums);
        for (int i = 0; i < nums.length; i++) {
            System.out.print(nums[i]+" ");
        }
        System.out.println();
    }
}
