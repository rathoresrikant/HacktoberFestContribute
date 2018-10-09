package main;

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
	
	public static Pair getMaxPair(Pair[] input) {
		if (input == null || input.length < 1)
			return null;
		
		Pair max =  input[0];
		
		for (int i = 1; i < input.length; i++) {
			Pair current = input[i];
			if (current.getSum() > max.getSum())
				max = current;
		}
		
		return max;
	}
	
	public static void main(String[] args) {
		Pair[] input = new Pair[] {
				new Pair(0, 2), 
				new Pair(5, 2), 
				new Pair(3, 2), 
				new Pair(5, 2), 
				new Pair(-1, 2)}; 
		
		
		Pair max = getMaxPair(input);
		
		System.out.println(max);
		System.out.println("Sum: " + max.getSum());
	}
}
