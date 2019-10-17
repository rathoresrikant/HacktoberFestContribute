import java.util.Scanner;
class numberType
{
	static int n;
	public static void main(String args[])
	{
		Scanner obj= new Scanner(System.in);
		System.out.println("enter\n1-for Armstrong Number\n2-for Perfect Number\n3-Magic Number\n4-Palindrome Number\n5-Prime Number\nany other to exit");
		int choice= obj.nextInt();
		System.out.println("enter a number");
		 n=obj.nextInt();
		switch(choice)
		{
			case 1:armstrong();
			break;
			case 2:perfect();
			break;
			//case 3:magic();
			//break;
			case 4:palindrome();
			break;
			case 5:if(prime())
						System.out.println("yes, "+ n+" is a prime number");
					else
						System.out.println("no, "+ n+" is not a prime number");

			break;
			default: System.exit(0);
		}
		
		
	}
	public static void armstrong()
	{
		int r=0,q=n,sum=0;
		while(n!=0)
		{
			r=n%10;
			sum+=r*r*r;
			n/=10;
		}			
		if(q==sum)
			System.out.println("yes, "+ q+" is an armstrong number");
		else
			System.out.println("no, "+ q+" is not an armstrong number");

	}
	public static void perfect()
	{
		int sum=0;
		for(int i=1;i<n;i++)
		{
			if(n%i==0)
				sum+=i;
		}	
		if(n==sum)
			System.out.println("yes, "+ n+" is a perfect number");
		else
			System.out.println("no, "+ n+" is not a perfect number");

	}
	public static void palindrome()
	{
		int r=0,q=n,sum=0;
		while(n!=0)
		{
			r=n%10;
			sum=sum*10 +r;
			n/=10;
		}			
		if(q==sum)
			System.out.println("yes, "+ q+" is a palindrome number");
		else
			System.out.println("no, "+ q+" is not a palindrome number");

	}
	public static boolean prime()
	{
		for(int i=2;i<n;i++)
		{
			if(n%i==0)
				return false;
		}
		return true;
	}
	
	
	
		
}
