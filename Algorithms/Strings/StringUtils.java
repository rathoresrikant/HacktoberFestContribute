public class StringUtils
{
  public static String removeExtraSpaces(String a)
  {
    String spaceRemovedString = a.replaceAll("\\s+"," ");
    return spaceRemovedString.trim();
  }
  
  public static void main(String args[])
  {
	  String a = " a  j it    h  ";
	  System.out.println(removeExtraSpaces(a));
  }
}
