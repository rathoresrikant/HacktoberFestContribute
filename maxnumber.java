public class MaxWithoutIf {
    public static void main(String[] args) {
        int a = 5;
        int b = 10;

        int max = maxOfTwo(a, b);
        System.out.println("Max of " + a + " and " + b + " is: " + max);
    }

    public static int maxOfTwo(int a, int b) {
        // Calculate the difference
        int diff = a - b;

        // Using bitwise right shift to determine the sign of diff
        int sign = (diff >> 31) & 1; // 0 if a >= b, 1 if a < b

        // Using the formula to find max
        return a * (1 - sign) + b * sign;
    }
}
