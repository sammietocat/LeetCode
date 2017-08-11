public class Solution {
    public static int rob(int[] nums) {
        if (0==nums.length) {
            return 0;
        }else if (1 == nums.length) {
            return nums[0];
        }

        int[] amt = new int[nums.length];
        amt[0] = nums[0];
        amt[1] = (nums[0] > nums[1] ? nums[0] : nums[1]);

        for (int i = 2; i < nums.length; i++) {
            amt[i] = amt[i-2]+nums[i];
            if (amt[i]<amt[i-1]) {
                amt[i] = amt[i-1];
            }
            //amt[i] = (nums[i] > nums[i - 1] ? (amt[i - 2] + nums[i]) : amt[i - 1]);
        }

        return amt[amt.length-1];
    }

    public static void main(String[] args) {
        /**
         * test cases
         *  * []
         *  * [2 1]
         *  * [1 1 1]
         * */
        int[] nums = {2,1};

        System.out.println(rob(nums));
    }
}
