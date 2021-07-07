import java.util.ArrayList;
import java.util.Collections;
import java.util.HashSet;
import java.util.List;
import java.util.Scanner;
import java.util.Set;

public class alphacommonchars {
	public static void main(String[] args) {
		System.out.println("asd");
		Scanner kb = new Scanner(System.in);
		String a=kb.nextLine();
		String b=kb.nextLine();
		List<String> list=new ArrayList<String>();
		for(int i=0;i<a.length();i++){
			for(int k=0;k<b.length();k++){
				if(a.substring(i, i+1).equals(b.substring(k, k+1)))
					list.add(a.substring(i, i+1));
			}
		}
		Set<String> x = new HashSet<>();
		x.addAll(list);
		list.clear();
		list.addAll(x);
		Collections.sort(list);
		System.out.println(list);
	}
}
