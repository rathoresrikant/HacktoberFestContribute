public class SquareSubmatricesCounter {
    public static void main(String[] args) {
        int m = 4; // Number of rows
        int n = 5; // Number of columns

        int count = countSquareSubmatrices(m, n);
        System.out.println("Number of square submatrices: " + count);
    }

    public static int countSquareSubmatrices(int m, int n) {
        int totalCount = 0;

        // Iterate through all possible sizes of square matrices
        for (int k = 1; k <= Math.min(m, n); k++) {
            int numSquares = (m - k + 1) * (n - k + 1);
            totalCount += numSquares;
        }

        return totalCount;
    }
}
