/**
 * Created by loccs on 6/15/17.
 */
public class Solution {
    public static String convert(String s, int numRows) {
        if ((1 == numRows) || (s.length()<=numRows)) {
            return s;
        }

        StringBuilder zigZag = new StringBuilder("");

        int numCols = (int) (Math.ceil(s.length() * 1.0 / (2 * numRows - 2)));
        System.out.println("s.length() = " + s.length());
        System.out.println("numCols = " + numCols);

        int offset;
        // estimate the 1st row
        for (int i = 0; i < numCols; i++) {
            offset = i * 2 * (numRows - 1);
            zigZag.append(s.charAt(offset));
        }

        // row 2 to last but one row
        for (int i = 1; i < numRows - 1; i++) {
            for (int j = 0; j < numCols; j++) {
                offset = j * 2 * (numRows - 1)+i;
                if (offset>=s.length()) { break; }
                zigZag.append(s.charAt(offset));

                offset += 2*(numRows-i-1);
                if (offset<s.length()) {
                    zigZag.append(s.charAt(offset));
                }
            }
        }

        // estimate the last row
        offset = numRows - 1;
        while (offset < s.length()) {
            zigZag.append(s.charAt(offset));
            offset += 2 * (numRows - 1);
        }

        return zigZag.toString();
    }

    public static void main(String[] args) {
        String s = "A";
                //"PAYPALISHIRING";
        int numRows = 3;

        System.out.println(convert(s, numRows));
    }
}
