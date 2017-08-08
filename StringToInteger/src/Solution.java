/**
 * Created by loccs on 6/11/17.
 */
public class Solution {
    public static int myAtoi(String str) {
        final int INT_MIN = 0x80000000;
        final int INT_MAX = 0x7fffffff;

        // trim out heading white space
        int j = 0;
        while((j<str.length()) && (' '==str.charAt(j))) { j++; }
        if (j>=str.length()) {
            return 0;
        }

        // check the sign of the integer
        int sign = 1;
        if('-'==str.charAt(j)) {
            sign = -1;
            j++;
        }else if('+'==str.charAt(j)) {
            sign = 1;
            j++;
        }

        // trim out the tailing invalid string
        int k = j;
        while((k<str.length()) && (Character.isDigit(str.charAt(k)))) {k++;}
        // the string has no digits
        if (k==j) {
            return 0;
        }

        // an ad-hoc length check
        if (k-j>String.valueOf(INT_MIN).length()) {
           return (-1==sign ? INT_MIN:INT_MAX);
        }

        long i = 0;
        for (int l = j; l < k; l++) {
           i = i*10+(long)(str.charAt(l)-'0');
        }

        // specially for Integer.MIN_VALUE
        if(sign*i<=INT_MIN) {
            return INT_MIN;
        }
        // underflow || overflow
        if(sign*i>=INT_MAX){
           return INT_MAX;
        }

        return sign*(int)i;
    }

    public static void main(String[] args) {
        long i = 0x80000000;
        System.out.println((int)i);
        System.out.println(myAtoi("+1"));
        //System.out.println(myAtoi("  -1"));
        //System.out.println(String.valueOf(0x80000000));
        System.out.println(String.valueOf(Integer.MIN_VALUE)+ " <-> "+myAtoi(String.valueOf(Integer.MIN_VALUE)));
        System.out.println(String.valueOf((long)(Integer.MIN_VALUE)-2)+ " <-> "
                +myAtoi(String.valueOf((long)(Integer.MIN_VALUE)-2)));
        System.out.println(String.valueOf((long)(Integer.MAX_VALUE)+2)+ " <-> "
                +myAtoi(String.valueOf((long)(Integer.MAX_VALUE)+2)));
        System.out.println("9223372036854775809 <-> "+myAtoi("9223372036854775809"));
        System.out.println("-9223372036854775809 <-> "+myAtoi("-9223372036854775809"));
    }
}
