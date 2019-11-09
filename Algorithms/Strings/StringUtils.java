import java.io.*;

public class StringUtils
{
  public static String removeAllVowels(String a)
  {
    return a.replaceAll("[aeiouAEIOU]","");
  }
  
  public static void main(String args[])
  {
    String test = "Hacktoberfest";
    System.out.println(removeAllVowels(test));
  }
}
