package main;

import java.util.Arrays;
import java.util.List;

public class MaxPair {

	public static class Pair
	{
		private int left;
		private int right;
			
		public Pair(int left, int right) {
			super();
			this.left = left;
			this.right = right;
		}
		
		public int getLeft() {
			return left;
		}
		public void setLeft(int left) {
			this.left = left;
		}
		public int getRight() {
			return right;
		}
		public void setRight(int right) {
			this.right = right;
		}
		
		public int getSum() {
			return left + right;
		}

		@Override
		public String toString() {
			return "Pair [left=" + left + ", right=" + right + "]";
		}
	}
	
	public static Pair getMaxPair(List<Pair> input) {
		if (input == null || input.isEmpty())
			return null;
		
		Pair max =  input.get(0);
		
		for (int i = 1; i < input.size(); i++) {
			Pair current = input.get(i);
			if (current.getSum() > max.getSum())
				max = current;
		}
		
		return max;
	}
	
	public static void main(String[] args) {
		List<Pair> input = Arrays.asList(
				new Pair(0, 2), 
				new Pair(5, 2), 
				new Pair(3, 2), 
				new Pair(5, 2), 
				new Pair(-1, 2)); 
		
		
		Pair max = getMaxPair(input);
		
		System.out.println(max);
		System.out.println("Sum: " + max.getSum());
	}
}
