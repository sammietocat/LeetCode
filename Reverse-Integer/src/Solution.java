/**
 * Created by loccs on 6/11/17.
 */
public class Solution {
    public static int reverse(int x) {
       long xRev = 0;
       int xSign = (x>=0 ? 1:-1);

       x *= xSign;
       while(x!=0) {
           xRev = 10*xRev+x%10;
          x/=10;
       }

       if(0!=(xRev>>31)) {
           return 0;
       }

       return xSign*(int)xRev;
    }

    public static void main(String[] args) {
        System.out.println(reverse(123));
        System.out.println(((1<<31)-1)+"<->"+reverse((1<<31)-1));
        System.out.println(reverse(-123));
    }
}
