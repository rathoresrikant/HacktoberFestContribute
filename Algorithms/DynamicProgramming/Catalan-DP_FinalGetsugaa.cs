// A dynamic programming based 
// Approach to find nth 
// Catalan number 
using System; 
  
public class CatalanDP 
{ 
      

static int catalanDP(int n) 
{ 
    // Table to store results of subproblems 
    int[] dp = new int[n + 2]; 
  
    // Initialize first two values of Catalan Number of position 0 and 1 --> 1
    dp[0] = 1;
	dp[1] = 1; 
  
    // Filling entries in dp[]  
    for (int i = 2; i <= n; i++) 
    { 
        dp[i] = 0; 
        for (int j = 0; j < i; j++) 
            dp[i] += dp[j] * dp[i - j - 1]; 
    } 
  
    return dp[n]; 
} 
   
static public void Main() 
{ 
    string val;
     val = Console.ReadLine();

     int num = Convert.ToInt32(val);
     Console.WriteLine("Catalan Number Corresponding to entered position is:");
     Console.Write(catalanDP(num)); 
} 
} 
