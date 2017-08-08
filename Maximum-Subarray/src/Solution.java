/**
 * Created by loccs on 6/15/17.
 */
public class Solution {
    public static int maxSubArray(int[] nums) {
        if (0 == nums.length) {
            return 0;
        }

        int[] maxSubSum = new int[nums.length];

        maxSubSum[0] = nums[0];
        for (int i = 1; i < nums.length; i++) {
            maxSubSum[i] = (maxSubSum[i - 1] + nums[i] > nums[i] ? (maxSubSum[i - 1] + nums[i]) : nums[i]);
        }

        for (int i = 1; i < maxSubSum.length; i++) {
           if (maxSubSum[i]>maxSubSum[0]) {
               maxSubSum[0] = maxSubSum[i];
           }
        }

        return maxSubSum[0];
    }

    public static void main(String[] args) {
        int[] nums = {-2,1,-3,4,-1,2,1,-5,4};

        System.out.println(maxSubArray(nums));
    }
}
