/**
 * Created by loccs on 6/12/17.
 */
public class Solution {
    public static String longestCommonPrefix(String[] strs) {
        if (0==strs.length) {
            return "";
        }

       StringBuilder LCP = new StringBuilder(strs[0]);

       int offset = LCP.length();
        for (int i = 1; i < strs.length; i++) {
            if (offset>strs[i].length()) {
                offset = strs[i].length();
            }

            for (int j = 0; j <offset; j++) {
               if (LCP.charAt(j)!=strs[i].charAt(j)) {
                   // update offset
                   offset = (j<offset ? j:offset);
                   break;
               }
            }

            // jump out in case of empty LCP
            if (0==offset) {
                break;
            }
        }

       return (0==offset ? "":LCP.substring(0,offset));
    }

    public static void main(String[] args) {
        String[] strs = {
                "aa",
                "a",
                ""
        };

        String LCP = longestCommonPrefix(strs);
        System.out.println(LCP);
    }
}
