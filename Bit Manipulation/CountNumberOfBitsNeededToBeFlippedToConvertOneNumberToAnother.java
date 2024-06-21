// Count number of bits to be flipped to convert A into B 
import java.util.*; 
  
class Count { 
      
    // Function to count set bits 
    public static int countSetBits(int n) 
    { 
        int count = 0; 
        while (n != 0) { 
            count += n & 1; 
            n >>= 1; 
        } 
        return count; 
    } 
  
    // Function to count flipped numbers 
    public static int FlippedCount(int a, int b) 
    { 
        return countSetBits(a ^ b); 
    } 
      
    //Main method 
    public static void main(String[] args) 
    { 
        int a = 12; 
        int b = 20; 
        System.out.print(FlippedCount(a, b)); 
    } 
} 
