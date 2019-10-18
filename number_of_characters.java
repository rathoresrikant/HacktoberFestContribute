import java.util.Scanner;
class Main 
{ 
  
    static int countOccurrences(int arr[], int n, int x) 
    { 
        int res = 0; 
        for (int i=0; i<n; i++) 
            if (x == arr[i]) 
              res++; 
        return res; 
    } 
      
    public static void main(String args[]) 
    { 
      Scanner sc=new Scanner(System.in);
        int arr[] =new int[100];
        
        int n = arr.length; 
        for(int i=0;i<n;i++)
          arr[i]=sc.nextInt();
        int x = 2; 
        System.out.println(countOccurrences(arr, n, x)); 
    } 
} 
