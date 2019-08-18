package main;

import java.util.Arrays;
import java.util.List;
import java.util.Random;

public class SecondLargest {
	
	public static Integer getSecondLargest(List<Integer> input, boolean considerDuplicate)
	{
		if (input == null || input.isEmpty())
			return null;
		
		Integer previousMax = Integer.MIN_VALUE;
		Integer currentMax = Integer.MIN_VALUE;
		
		if (considerDuplicate) {
			//Find the second largest number. If the input list contains duplicates of the maximum, 
			//the duplicate closest to the last occurrence of the maximum element will be returned
			for (Integer value : input) {
				if (value > previousMax)
				{
					if (value >= currentMax)
					{
						previousMax = currentMax;
						currentMax = value;
					}
					else
					{
						previousMax = value;
					}
				}
			}
		}
		else
		{
			//Find the second largest number ignoring any duplicate of the maximum
			for (Integer value : input) {
				if (value > previousMax)
				{
					if (value > currentMax)
					{
						previousMax = currentMax;
						currentMax = value;
					}
					else if (value != currentMax)
					{
						previousMax = value;
					}
				}
			}
		}
		
		return previousMax;
	}
	
	public static void main(String[] args) 
	{
		Random rand = new Random();
		List<Integer> input = Arrays.asList(
				rand.nextInt(10), rand.nextInt(10), rand.nextInt(10),
				rand.nextInt(10), rand.nextInt(10), rand.nextInt(10));
		
		Integer result = getSecondLargest(input, false);
		
		System.out.println("Input: " + input);
		System.out.println(result);
	}

}
