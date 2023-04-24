
/* C# program to push zeroes to back of array */
using System; 
  
public class PushZeroAtEnd 
{ 
    // Function which pushes all zeros  
    // to end of an array. 
    static void ZerosToEnd(int []arr, int n) 
    { 
        // Count of non-zero elements 
        int count = 0;  
          
        // Traverse the array. If element encountered is 
        // non-zero, then replace the element  
        // at index â..countâ.. with this element 
        for (int i = 0; i <n; i++) 
        if (arr[i] != 0) 
          
        // here count is incremented 
        arr[count++] = arr[i];  
          
        // Now all non-zero elements have been shifted to 
        // front and â..countâ.. is set as index of first 0. 
        // Make all elements 0 from count to end. 
        while (count < n) 
        arr[count++] = 0; 
    } 
      
    
    public static void Main () 
    {  
	Console.WriteLine("Enter Number of Elements in  Array:"); 
	string val;
        val = Console.ReadLine();

        int num = Convert.ToInt32(val);
	int[] arr = new int[num];
	Console.WriteLine("Enter Array Elements:"); 
	int i;
		
	for(i=0; i<num; i++)  
	        arr[i] = Convert.ToInt32(Console.ReadLine());  		
       
        ZerosToEnd(arr, num); 
        Console.WriteLine("Array after doing the operation: "); 
        for (i = 0; i <num; i++) 
        Console.Write(arr[i] +" "); 
    } 
} 
