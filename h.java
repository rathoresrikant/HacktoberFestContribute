class StringReverse
{
	public static void main(String[] args)
	{
		Scanner sc=new Scanner(System.in);
		String s=sc.nextLine();

		char[] c=s.toCharArray();
		for(int i=c.length;i>=1;i–)
		{
			System.out.print(c[i-1]);
		}
	}
}
