
// C# program to find nth element 
// of Newman-Conway Sequence 
using System; 
  
public class NewConvSeq { 
      
    // Using Recursion  
    static int newmanconvoy(int n) 
    { 
        if (n == 1 || n == 2)            // Base case 
            return 1; 
        else
            return newmanconvoy(newmanconvoy(n - 1)) + newmanconvoy 
                           (n - newmanconvoy(n - 1)); 
    } 
      
    public static void Main() 
    {  
		string val;
        val = Console.ReadLine();

        int num = Convert.ToInt32(val);
        Console.WriteLine("Newman Convoy Number Corresponding to entered position is:");
        Console.Write(newmanconvoy(num)); 
    } 
} 
