/**
 * Created by loccs on 6/23/17.
 */
public class Solution {
    public static String convertToTitle(int n) {
        StringBuffer str = new StringBuffer("");

        while (n>0) {
            str.append((char)('A'+(n-1)%26));
            n = (n-1)/26;
        }

        return str.reverse().toString();
    }

    public static void main(String[] args) {
        for (int i = 1; i < 131; i++) {
            System.out.println(i + " ->" + convertToTitle(i));
        }
    }
}
