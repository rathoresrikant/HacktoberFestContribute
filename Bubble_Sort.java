import java.util.*;
public class Bubble_Sort {

    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);
        int size, count = 0;
        System.out.print("Enter Number Of Elements ");
        size = s.nextInt();
        int list[] = new int[size];
        System.out.println("Enter any " + size + " integer numbers: ");
        for(int i = 0; i < size; i++)
            list[i] = s.nextInt();
        int temp=0;
        for(int i=0;i<size-1;i++) {
            for(int j=0;j<size-i-1;j++) {
                if(list[j]<list[j+1]) {
                    temp=list[j];
                    list[j]=list[j+1];
                    list[j+1]=temp;
                    count++;
                }
            }
        }
        System.out.println("Elements After Sorting");
        for(int x:list) {
            System.out.print(x + "   ");
        }
    }
}
