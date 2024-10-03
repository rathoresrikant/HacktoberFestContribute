import java.util.Scanner;
public class Catalan {

    // A recursive function to print first n catalan numbers

    int catalan(int n) {
        int res = 0;

        // Base case
        if (n <= 1) {
            return 1;
        }
        for (int i = 0; i < n; i++) {
            res += catalan(i) * catalan(n - i - 1);
        }
        return res;
    }

    public static void main(String[] args) {
        Catalan cn = new Catalan();
        Scanner input = new Scanner(System.in);
        int n= input.nextInt();
        for (int i = 0; i < n; i++) {
            System.out.print(cn.catalan(i) + " ");
        }
    }
}