import java.util.*;

public class ReverseString{
	public static void main(String []args){
		String name = "Vidurangha";
		Stack<Character> ob = new Stack<Character>();
		for(int i=0;i<name.length();i++){
			ob.push(name.charAt(i));
		}
		while(!ob.isEmpty())
			System.out.print(ob.pop());
		System.out.println();
	}
}