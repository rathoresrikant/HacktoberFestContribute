import java.util.*;

class Binary  
{ 
static void bin(int n) 
{ 
    /* step 1 */
    if (n > 1) 
        bin(n/2); 
  
    /* step 2 */
    System.out.print(n % 2); 
} 
  
//Driver code 
public static void main(String[] args)  
{ 	
	int x;
	Scanner sc=new Scanner(System.in);
	x=sc.nextInt();
    bin(x);      
} 
} 
