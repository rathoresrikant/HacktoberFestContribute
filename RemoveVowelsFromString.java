import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.Scanner;

public class RemoveVowelsFromString {

  public static void main(String[] args) {
    Scanner scanner = new Scanner(System.in);

    System.out.print("Input string: ");
    String line = scanner.nextLine();

    List<Character> list = new ArrayList<>();

    for (int i = 0; i < line.length(); i++) {
      list.add(line.charAt(i));
    }

    List<Character> vowels = new ArrayList<>(Arrays.asList('a', 'e', 'i', 'o', 'u'));

    list.removeAll(vowels);

    System.out.print("String: ");
    
    for (char c : list) {
      System.out.print(c);
    }
  }
}