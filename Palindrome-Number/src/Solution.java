/**
 * Created by loccs on 6/11/17.
 */
public class Solution {
    public static boolean isPalindrome(int x) {
        if(x<0) {
            return false;
        }

        int e10 = (int)(Math.log10(x));
        if(0==e10) {
            // case: 0-9
            return true;
        }

        // case: >=10
        boolean yes = true;
        long pow10 = (long)(Math.pow(10,e10));

        int y = x;
        //System.out.println("e10 = "+e10);
        for (int j = 0; j < (e10+1)/2; j++) {
            /*
            System.out.println("***");
            System.out.println("j = "+j);
            System.out.println("y = "+y);
            System.out.println("pow10 = "+pow10);
            System.out.println("y/pow10 = "+(y/pow10));
            System.out.println("y%10 = "+y%10);
            */

            if (y/pow10 != y % 10) {
                yes = false;
                break;
            }

            y = (int)(y%pow10);
            y /= 10;
            pow10 /= 100;
        }

        return yes;
    }

    public static void main(String[] args) {
        System.out.println(isPalindrome(121));
        //System.out.println(isPalindrome(-2147483648));
        //System.out.println(isPalindrome(1000021));
        System.out.println(isPalindrome(10));
        System.out.println(isPalindrome(11));
        //System.out.println(isPalindrome(88888));
        //System.out.println(isPalindrome(1000030001));
    }
}
