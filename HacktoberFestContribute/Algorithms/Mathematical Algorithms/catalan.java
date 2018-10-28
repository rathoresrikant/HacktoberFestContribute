import java.util.*;
import java.math.*;

public class catalan {
    final static int size = 10100;
    final static BigInteger TWO = new BigInteger("2");
    public static BigInteger ans[] = new BigInteger[size];
    public static void runFactorial() {
        ans[1] = BigInteger.ONE;
        ans[2] = TWO;
        for ( int i = 3; i < size; i++ ) {
            ans[i] = ans[i-1].multiply(BigInteger.valueOf(i));
        }
    }

    public static BigInteger getCatalan(int n) {
        BigInteger resp = new BigInteger("-1");
        try {
            BigInteger a = ans[2*n];
            BigInteger b = ans[n].multiply(ans[n]);
            resp = a.divide(b);
            n++;
        } catch (Exception e) {
            System.out.println(e);
            return resp;
        }
        return resp.divide(BigInteger.valueOf(n));
    }

    public static void main(String args[]) {
        runFactorial();
        Scanner scan = new Scanner(System.in);
        int n = scan.nextInt();
        for (int i = 1; i <= n; i++) {
            System.out.println(getCatalan(i));
        }
        scan.close();
    }
}
