import java.util.HashMap;
import java.util.Map;

public class Solution {
    public static int findPairs(int[] nums, int k) {
        int m = 0;
        if (k < 0) {
            return m;
        }

        Map<Integer, Integer> seen = new HashMap<>();
        for (int i = 0; i < nums.length; i++) {
            for (int j = i + 1; j < nums.length; j++) {
                if (nums[i] - nums[j] == k) {
                    if (null == seen.get(nums[j])) {
                        ++m;
                        seen.put(nums[j], nums[i]);
                    }
                } else if (nums[j] - nums[i] == k) {
                    if (null == seen.get(nums[i])) {
                        ++m;
                        seen.put(nums[i], nums[j]);
                    }
                }
            }
        }

        return m;
    }

    public static void main(String[] args) {
        /** case 1
         final int k = 2;
         int[] nums = new int[]{3, 1, 4, 1, 5};
         */

        ///**case 2
        final int k = 1;
        int[] nums = new int[]{1, 2, 3, 4, 5};
        //*/

        /*
        final int k = 0;
        int[] nums = new int[]{1, 3, 1, 5, 4};
        */

        System.out.println(findPairs(nums, k));

    }
}
