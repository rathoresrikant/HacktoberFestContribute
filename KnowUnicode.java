//This is Very Basic Program for Checking Unicode Value of a Single Character
//Enter Your Character to see it's Unicode Value
import java.util.*;
class Unicode
{
    public static void main(String[] args) 
    {
        Scanner input = new Scanner(System.in);
        System.out.println("Enter Your Desired Character");
        char ch = input.next().charAt(0);
        System.out.println("Unicode value for "+ch+" = "+(int)ch);
       }
}
