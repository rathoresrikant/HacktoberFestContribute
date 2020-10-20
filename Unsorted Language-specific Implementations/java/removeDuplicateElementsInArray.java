import java.util.Scanner;
public class RemoveDuplicateElements{  
  public static void main(String[] args){  
    int n=20;
    int[] tempArr = new int[n];
    Scanner s = new Scanner(System.in);
    System.out.println("Enter size of array");
    int arrSize = s.nextInt();
    System.out.println("Enter array elements");
    int[] arr = new int[arrSize];
    int i;
    for(i=0;i<arrSize;i++){
      arr[i] = s.nextInt(); 
    }
    int j=0;
    for(i=0;i<arrSize;i++){
      for(j=0;j<arrSize-1;j++){
        if(arr[j] > arr[j+1]){
       	  int k=0;
	  k=arr[j];
	  arr[j]=arr[j+1];
	  arr[j+1]=k;
        }
      }
    }
    int k=0;
    for (i=0; i<arrSize -1; i++){  
      if (arr[i] != arr[i+1]){  
        tempArr[k] = arr[i];  
	k++;
      }  
    }  
    tempArr[k] = arr[arrSize -1];  
    k++;   
    System.out.println("after:");
    int m; 
    for(m=0;m<k;m++){
      System.out.println(tempArr[m]);
    }
  }
}

