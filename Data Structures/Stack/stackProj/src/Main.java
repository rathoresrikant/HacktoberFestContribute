import java.util.Stack;

public class Main {

    public static void main(String []args) {

        Stack<Character> stack = new Stack();
        String in = "hacktoberfest";
        for (int i = 0; i < in.length(); i++)
            stack.push(in.charAt(i));
        for (int i = 0; i < in.length(); i++) {
            char c = (char) stack.pop();
            System.out.print(c);
        }
    }


}
