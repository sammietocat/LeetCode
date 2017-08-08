/**
 * Created by loccs on 6/12/17.
 */
public class Solution {
    public static int strStr(String haystack, String needle) {
        if (null==haystack || null==needle) {
            return -1;
        }
        if (0==needle.length()) {
            return 0;
        }

        int idx = -1;
        for (int i = 0; i <= haystack.length()-needle.length(); i++) {
            idx = i;
            for (int j = 0; j < needle.length(); j++) {
               if (haystack.charAt(i+j)!=needle.charAt(j)){
                  idx = -1;
                  break;
               }
            }
            if (-1!=idx) {
                break;
            }
        }

        return idx;
    }

    public static void main(String[] args) {
        String haystack = "1hello";
        String needle = "hello";

        System.out.println(strStr(haystack, needle));
    }
}
