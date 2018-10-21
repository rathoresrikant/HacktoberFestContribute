import java.util.List;
import java.util.ArrayList;
import java.util.Collections;

public class StringUtil
{
  public static List<Character> getSortedCommonChars(String a, String b)
  {
    List<Character> commonChars = new ArrayList<>();
    int freq[] = new int[26];
    
    for(int i=0; i<a.length(); i++)
    {
      freq[a.charAt(i)-'a']++;
    }
    
    for(int i=0; i<b.length(); i++)
    {
      if(freq[b.charAt(i)-'a'] > 0)
      {
        commonChars.add(b.charAt(i));
        freq[b.charAt(i)-'a']--;
      }
    }
    
    Collections.sort(commonChars);
    return commonChars;
  }
  
  public static void main(String args[])
  {
	  String a = "ajith";
	  String b = "hacktoberfest";
	  System.out.println(getSortedCommonChars(a,b));	  
  }
}
