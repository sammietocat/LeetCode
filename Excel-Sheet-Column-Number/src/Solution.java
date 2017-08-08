/**
 * Created by loccs on 7/18/17.
 */
public class Solution {
    public static int titleToNumber(String s) {
        int num = 0;

        for (int i=0;i<s.length();i++) {
            num = num*26+(s.charAt(i)-'A'+1);
        }

        return num;
    }
    public static void main(String[] args) {
        System.out.println(titleToNumber("A"));
    }
}
