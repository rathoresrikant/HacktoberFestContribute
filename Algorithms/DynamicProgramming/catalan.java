import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class catalan{
    public static int catalanDP(int num){
        int cat[] = new int[num + 2];
        cat[0] = 1;
        cat[1] = 1;

        for (int i = 2; i <= num; i++){
            cat[i] = 0;
            for (int j = 0; j < i; j++){
                cat[i] += cat[j] * cat[i-j-1];
            }
        }
        return cat[num];
    }

    public static void main(String args[]) throws IOException {
        InputStreamReader in = new InputStreamReader(System.in);
        BufferedReader br = new BufferedReader(in);
        System.out.println("Enter number: ");
        int num = Integer.parseInt(br.readLine());
        System.out.println(catalanDP(num));
    }
}
