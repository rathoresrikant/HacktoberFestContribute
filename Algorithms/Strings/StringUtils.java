import java.io.*;

public class StringUtils
{
  public static Character getFirstNonRepeatingCharacter(String a)
  {
	int freq[] = new int[26];
	for(int i=0; i<a.length(); i++)
	{
		char c = a.charAt(i);
		char index = Character.isLowerCase(c) ? 'a' : 'A';
		freq[c-index]++;
	}
	for(int i=0; i<a.length(); i++)
	{
		char c = a.charAt(i);
		char index = Character.isLowerCase(c) ? 'a' : 'A';
		if(freq[c-index] == 1)
		{
			return c;
		}
	}
    return null;
  }
  
  public static void main(String args[])
  {
    String test = "Hacktoberfest";
    System.out.println(getFirstNonRepeatingCharacter(test));
  }
}
