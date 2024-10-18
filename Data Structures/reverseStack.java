import java.util.Stack;

public class ReverseStringUsingStack {
    public static String reverseString(String str) {
        Stack<Character> stack = new Stack<>();

        // Push each character onto the stack
        for (char c : str.toCharArray()) {
            stack.push(c);
        }

        StringBuilder reversedString = new StringBuilder();

        // Pop each character from the stack to reverse the string
        while (!stack.isEmpty()) {
            reversedString.append(stack.pop());
        }

        return reversedString.toString();
    }

    public static void main(String[] args) {
        // Input from user
        java.util.Scanner scanner = new java.util.Scanner(System.in);
        System.out.print("Enter a string to reverse: ");
        String input = scanner.nextLine();

        String reversed = reverseString(input);
        System.out.println("Reversed string: " + reversed);
        
        scanner.close();
    }
}
