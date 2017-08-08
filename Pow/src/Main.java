public class Main {
    public static double myPow(double x, int n) {
        if (0 == x) {
            return 0;
        } else if (0 == n) {
            return 1;
        } else if (n < 0) {
            x = 1 / x;
            n = -n;
        }


        // find the highest bit of n
        int msbIdx = 32;
        while (0 == (n >> (--msbIdx))) ;

        //System.out.println("msbIdx = " + msbIdx);

        double pow = 1;
        double y = x;
        for (int i = 0; i <= msbIdx; i++) {
            //System.out.println("i=" + i + ", y=" + y);
            if (0 != (n & (1 << i))) {
                //if (0 != (n >> i)) {
                pow *= y;
            }
            y *= y;
        }

        return pow;
    }

    public static void main(String[] args) {
        final double x = 2.0;
        final int n = -1;

        System.out.println(Integer.toBinaryString((int) x));
        System.out.println(Integer.toBinaryString(n));
        System.out.println(myPow(x, n));
    }
}
