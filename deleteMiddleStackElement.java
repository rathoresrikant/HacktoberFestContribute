
import java.io.*;
import java.util.*;

public class deleteMiddleStackElement {

  public static void main(String args[]) {
    Stack<String> stack = new Stack<String>();

    stack.push("1");
    stack.push("2");
    stack.push("3");
    stack.push("4");
    stack.push("5");
    stack.push("6");
    stack.push("7");
    stack.push("8");
    stack.push("9");
    stack.push("10");
    stack.push("11");

    deleteMiddle(stack, stack.size(), 0);

    while (!stack.empty()) {
      System.out.print(stack.pop() + "\n");
    }
  }

  static void deleteMiddle(Stack<String> stack, int initialSize, int index) {

    // Check for when the stack is empty
    if (stack.empty() || index == initialSize)
      return;

    String element = stack.pop();

    // Calls recursive function on modified stack
    deleteMiddle(stack, initialSize, index + 1);

    // Put all items back except middle
    if (index != initialSize / 2)
      stack.push(element);
  }
}