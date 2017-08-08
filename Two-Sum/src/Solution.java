/**
 * Created by loccs on 6/11/17.
 */
public class Solution {
    public static int[] twoSum(int[] nums, int target) {
        int[] idx = {-1,-1};

        for (int i = 0; i < nums.length-1; i++) {
            for (int j = i+1; j < nums.length; j++) {
               if (nums[i]+nums[j]==target) {
                  idx[0] = i;
                  idx[1] = j;
               }
            }
            if(idx[0]!=-1){
                break;
            }
        }

        return idx;
    }

    public static void main(String[] args){
        int[] nums = {2,7,11,15};
        int target = 9;

        int[] idx = twoSum(nums, target);
        System.out.println(idx[0]+" "+idx[1]);
    }
}
