
import java.io.*;
import java.util.*;

public class reverseStack {

  public static void main(String args[]) {
    Stack<String> stack = new Stack<String>();
    Stack<String> reversedStack = new Stack<String>();

    stack.push("11");
    stack.push("10");
    stack.push("9");
    stack.push("8");
    stack.push("7");
    stack.push("6");
    stack.push("5");
    stack.push("4");
    stack.push("3");
    stack.push("2");
    stack.push("1");

    reverse(stack, reversedStack, stack.size(), 0);

    System.out.print("Initial Stack Values\n");
    while (!stack.empty()) {
      System.out.print(stack.pop() + " ");
    }

    System.out.print("\n\nReversed Stack Values\n");
    while (!reversedStack.empty()) {
      System.out.print(reversedStack.pop() + " ");
    }
    System.out.print("\n");
  }

  static void reverse(Stack<String> stack, Stack<String> reversedStack, int initialSize, int index) {

    // Check for when the stack is empty
    if (stack.empty() || index == initialSize)
      return;

    String element = stack.pop();
    reversedStack.push(element);

    // Calls recursive function on modified stack
    reverse(stack, reversedStack, initialSize, index + 1);

    // Put all items back
    stack.push(element);
  }
}