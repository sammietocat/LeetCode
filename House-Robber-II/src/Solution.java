public class Solution {
    public static int rob(int[] nums) {
        if (0 == nums.length) {
            return 0;
        } else if (1 == nums.length) {
            return nums[0];
        } else if (2 == nums.length) {
            return (nums[0] > nums[1] ? nums[0] : nums[1]);
        }

        int amtMax = 0, amtTmp;
        for (int offset = 0; offset < nums.length; offset++) {
            amtTmp = rob(nums, offset);
            if (amtMax < amtTmp) {
                amtMax = amtTmp;
            }
        }

        return amtMax;
    }

    public static int rob(int[] nums, int offset) {
        if ((offset > nums.length - 1) || (offset < 0)) {
            return 0;
        }

        int[] pre = new int[nums.length - 1];

        int[] amt = new int[nums.length - 1];
        amt[0] = nums[offset];
        pre[0] = offset;

        int i = (offset + 1) % nums.length;
        amt[1] = (nums[offset] > nums[i] ? nums[offset] : nums[i]);
        pre[1] = (nums[offset] > nums[i] ? offset : i);

        int j = 1;
        while ((++j < amt.length) && (++i < nums.length)) {
            amt[j] = amt[j - 2] + nums[i];
            pre[j] = j;
            if (amt[j] < amt[j - 1]) {
                amt[j] = amt[j - 1];

                pre[j] = pre[j - 1];
            }
        }

        // wrap around
        i = -1;
        while ((++j < amt.length) && (++i < offset - 1)) {
            amt[j] = amt[j - 2] + nums[i];
            pre[j] = j;
            if (amt[j] < amt[j - 1]) {
                amt[j] = amt[j - 1];

                pre[j] = pre[j - 1];
            }
        }

        {
            System.out.println("offset = " + offset);
            int k = pre.length;
            while (--k >= 0) {
                if (k == pre[k]) {
                    System.out.print("(" + pre[k] + "," + nums[pre[k]] + ") ");
                    k -= 1;
                }
            }
            /*
            while (pre[--k] != -1) {
                System.out.print("(" + pre[k] + "," + nums[pre[k]] + ") ");
            }
            */
            System.out.println();
            System.out.println("with max as " + amt[amt.length - 1]);
        }

        return amt[amt.length - 1];
    }

    public static void main(String[] args) {
        /**
         * test cases
         *  * []
         *  * [2 1]
         *  * [1 1 1]
         *  * [6,3,10,8,2,10,3,5,10,5,3]
         * */
        int[] nums = {6, 3, 10, 8, 2, 10, 3, 5, 10, 5, 3};

        System.out.println(rob(nums));
    }
}
