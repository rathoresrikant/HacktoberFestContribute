import java.util.*;
import java.lang.Math;

public class Rotate{
	public static void main(String[] args) {
		Scanner scn = new Scanner(System.in);
		int num = scn.nextInt();
		int rotation = scn.nextInt();

		int digitCount = 0;
		int temp = num;
		while(temp > 0){
			temp = temp / 10;
			++digitCount;	
		}

		int rotate = rotation % digitCount;

		int pairFront = num % ((int) Math.pow(10, rotate)) * ((int) Math.pow(10, (digitCount - rotate)));
		int pairBack = (num / ((int) Math.pow(10, rotate)));
		int result = pairBack + pairFront;

		System.out.println("Result :" + result);
	}
}
