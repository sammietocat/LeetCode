/**
 * Created by loccs on 7/18/17.
 */
public class Solution {
    public static String getPermutation(int n, int k) {
        byte[] m = new byte[n + 1];
        for (int i = 0; i < m.length; i++) {
            m[i] = 0;
        }

        int carry;
        while (k > 0) {
            carry = 1;
            for (int j = n; j > 0; j--) {
                m[j] += carry;
                //System.out.println("m["+j+"]="+m[j]);
                if (m[j] >= j) {
                    carry = 1;
                    m[j] = 0;
                }else {
                    carry = 0;
                }
            }

            k--;
        }

        for (int i = 1; i <= n; i++) {
            System.out.print(m[i]+" ");
        }
        System.out.println();

        // recover the permutation from the medium sequence
        char[] str = new char[n];
        for (int i = 0; i < str.length; i++) {
           str[i] = '1';
        }
        for (int i = n; i > 1; i--) {
            System.out.println("***");
            System.out.println("i = "+i+", m["+i+"] = "+m[i]);
            int j = n;
            //while ((m[i]>0) && (--j >0)) {
                while ((--j >0) && (m[i]>0)) {
                if (str[j] == '1') {
                    m[i]--;
                }
            }
            str[j] = (char)('0'+i);
            System.out.println("j = "+j+", i = "+i+", str = "+str[j]);
        }

        return new String(str);
    }

    public static void main(String[] args) {
        final int N = 3;
        for (int i = 1; i <= 6; i++) {
            System.out.println("********************");
            System.out.println(getPermutation(N,i));
        }
    }
}
