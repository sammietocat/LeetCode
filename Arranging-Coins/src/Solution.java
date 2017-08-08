/**
 * Created by loccs on 7/18/17.
 */
public class Solution {
    public static int arrangeCoins(int n) {
        int k =(int)(Math.sqrt(2L*n));
        return (1L*k*(k+1)<=2L*n) ? k:(k-1);
    }
    public static void main(String[] args) {
        /*
        for (int i = 0; i < 64; i++) {
            System.out.println(i+" -> "+arrangeCoins(i));
        }
        */

        int n = 1804289383;
        System.out.println(arrangeCoins(n));
    }
}
