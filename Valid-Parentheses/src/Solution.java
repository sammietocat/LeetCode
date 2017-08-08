/**
 * Created by loccs on 6/11/17.
 */
public class Solution {
    public static boolean isValid(String s) {
        StringBuilder stack = new StringBuilder();

        for (int i = 0; i < s.length(); i++) {
            if (('(' == s.charAt(i)) || ('{' == s.charAt(i)) || ('[' == s.charAt(i))) {
                stack.append(s.charAt(i));
            } else if (')' == s.charAt(i)) {
                if ((0==stack.length()) || (stack.charAt(stack.length()-1)!='(')) {
                    return false;
                }
                stack.deleteCharAt(stack.length()-1);
            } else if ('}' == s.charAt(i)) {
                if ((0==stack.length()) || (stack.charAt(stack.length()-1)!='{')) {
                    return false;
                }
                stack.deleteCharAt(stack.length()-1);
            } else if (']' == s.charAt(i)) {
                if ((0==stack.length()) || (stack.charAt(stack.length()-1)!='[')) {
                    return false;
                }
                stack.deleteCharAt(stack.length()-1);
            }
        }

        return (0==stack.length());
    }

    public static void main(String[] args) {
        String s = "{(()){}[]}";

        System.out.println(isValid(s));
    }
}
