import java.util.*;

public class CommonCharactersBetweenString {

  static void getCommonCharacter(String firstString, String secondString) {
    SortedSet<Character> firstSet = new TreeSet<>();
    SortedSet<Character> secondSet = new TreeSet<>();

    for (char c : firstString.toCharArray()) {
      firstSet.add(c);
    }

    for (char c : secondString.toCharArray()) {
      secondSet.add(c);
    }

    SortedSet<Character> intersection = new TreeSet<>(firstSet);
    intersection.retainAll(secondSet);

    System.out.println("Common Characters Between Two Strings: ");
    for (char c : intersection) {
      System.out.print(c + " ");
    }
  }

  public static void main(String[] args) {
    Scanner scanner = new Scanner(System.in);

    System.out.print("Input first string: ");
    String firstString = scanner.nextLine();

    System.out.print("Input second string: ");
    String secondString = scanner.nextLine();

    getCommonCharacter(firstString, secondString);
  }
}