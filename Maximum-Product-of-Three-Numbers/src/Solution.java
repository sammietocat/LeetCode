public class Solution {
    public static int maximumProduct(int[] nums) {
        if (3 == nums.length) {
            return nums[0] * nums[1] * nums[2];
        }

        int maxProd = nums[0] * nums[1] * nums[2];
        int[] idx = new int[4];
        if (nums[0]<nums[1]) {

        }

        for (int i = 0; i < nums.length; i++) {
            if (nums[i] < nums[idx[0]]) {
                idx[0] = i;
            }
            if (nums[i] > nums[idx[0]]) {
                idx[0] = i;
            }
        }


        return maxProd;
    }

    public static void main(String[] args) {

    }
}
