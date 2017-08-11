public class Solution {
    public static class TreeNode {
        int val;
        TreeNode left;
        TreeNode right;

        TreeNode(int x) {
            val = x;
        }
    }

    static String prefix = "*";

    public static int rob(TreeNode root) {
        if (null == root) {
            return 0;
        }

        TreeNode house2 = new TreeNode(0);

        rob(root, house2);

        return (root.val > house2.val ? root.val : house2.val);
    }

    public static void rob(TreeNode houses1, TreeNode houses2) {
        if (null == houses1) {
            return;
        }

        /*
        String depth = prefix;
        prefix += "*";
        System.out.println(depth + ": root=" + houses1.val);
        System.out.println(depth + ": left=" + (null == houses1.left ? "nil" : houses1.left.val));
        System.out.println(depth + ":right=" + (null == houses1.right ? "nil" : houses1.right.val));
        */
        if ((null != houses1.left) || (null != houses1.right)) {
            int[] amt = new int[]{0,0,0,0};

            if (null != houses1.left) {
                houses2.left = new TreeNode(0);

                rob(houses1.left, houses2.left);

                houses1.val += houses2.left.val;
                //houses2.val += houses1.left.val;

                //amt[0] = amt[1] = houses1.left.val;
                //amt[2] = amt[3] = houses2.left.val;
                amt[0] = houses1.left.val;
                amt[1] = houses1.left.val;
                amt[2] = houses2.left.val;
                amt[3] = houses2.left.val;
            }
            /*
            System.out.println(depth + "-: houses1.left=" + (null == houses1.left ? "nil" : houses1.left.val));
            System.out.println(depth + "-:houses1.right=" + (null == houses1.right ? "nil" : houses1.right.val));
            System.out.println(depth + "-: houses2.left=" + (null == houses2.left ? "nil" : houses2.left.val));
            System.out.println(depth + "-:houses2.right=" + (null == houses2.right ? "nil" : houses2.right.val));
            */

            if (null != houses1.right) {
                houses2.right = new TreeNode(0);

                rob(houses1.right, houses2.right);

                houses1.val += houses2.right.val;

                //houses2.val += houses1.right.val;
                amt[0] += houses1.right.val;
                amt[1] += houses2.right.val;
                amt[2] += houses1.right.val;
                amt[3] += houses2.right.val;
            }

            /*
            System.out.println(depth + ": houses1.left=" + (null == houses1.left ? "nil" : houses1.left.val));
            System.out.println(depth + ":houses1.right=" + (null == houses1.right ? "nil" : houses1.right.val));
            System.out.println(depth + ": houses2.left=" + (null == houses2.left ? "nil" : houses2.left.val));
            System.out.println(depth + ":houses2.right=" + (null == houses2.right ? "nil" : houses2.right.val));
            */
            for (int a : amt) {
                //System.out.print(depth + a + " ");
                if (houses2.val < a) {
                    houses2.val = a;
                }
            }
            //System.out.println();
        }

        /*
        System.out.println(depth + ": houses1.val=" + houses1.val);
        System.out.println(depth + ": houses2.val=" + houses2.val);
        */
    }

    public static void main(String[] args) {
        /**case 1
         TreeNode houses = new TreeNode(3);

         houses.left = new TreeNode(2);
         houses.left.right = new TreeNode(3);

         houses.right = new TreeNode(3);
         houses.right.right = new TreeNode(1);

         // expected 7
        */

        /**case 2
        TreeNode houses = new TreeNode(3);

        houses.left = new TreeNode(4);
        houses.left.left = new TreeNode(1);
        houses.left.right = new TreeNode(3);

        houses.right = new TreeNode(5);
        houses.right.right = new TreeNode(1);
         // expected 9
        */

        /*
        TreeNode houses = new TreeNode(4);
        houses.left = new TreeNode(1);
        houses.left.left = new TreeNode(2);
        houses.left.left.left = new TreeNode(3);
        // expected 7
        */

        TreeNode houses = new TreeNode(3);
        houses.left = new TreeNode(2);
        houses.left.right = new TreeNode(3);

        houses.right = new TreeNode(3);
        houses.right.right = new TreeNode(1);


        System.out.println(rob(houses));
    }
}
