import java.util.Scanner;
class fiboTribonacci
{
	static int n;
	public static void main(String args[])
	{
			Scanner obj= new Scanner(System.in);
			System.out.println("enter your choice:\n1-fibonacci series(0,1...)\n2-tribonacci series(0,0,1....)\nany other to exit");
			int choice=obj.nextInt();
			System.out.println("enter the number of terms");
			n=obj.nextInt();
			switch(choice)
			{
				case 1:fibo();
				System.out.println();
				break;
				case 2:tribo();
				System.out.println();
				break;
				default:System.exit(0);
			}
	}
	public static void fibo()
	{
		int a=0,b=1,c;
		System.out.print(a+"\t"+b+"\t");
		for(int i=1;i<=n;i++)
		{
			c=a+b;
			a=b;
			b=c;
			System.out.print(c+"\t");	
		}
	}
	
	public static void tribo()
	{
		int a=0,b=0,c=1,d;
					System.out.print(a+"\t"+b+"\t"+c+"\t");
		for(int i=1;i<=n;i++)
		{
			d=a+b+c;
			a=b;
			b=c;
			c=d;
			System.out.print(d+"\t");
		}
	}
}
