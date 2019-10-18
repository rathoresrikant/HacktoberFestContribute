public class BubbleSort {
    public static void bubbleSort(int a[]){
        int tmp;
        for(int i=0; i<a.length; i++){
            for(int j=0; j<a.length-1; j++){
                if(a[j]>a[j+1]){
                    tmp = a[j];
                    a[j] = a[j+1];
                    a[j+1] = tmp;
                }
            }
        }
    }

    public static void main(String args[]){
        int a[] = {433,7,243,8,22,88,113,87,34,66,1,3,54,7,23,76,23};
        bubbleSort(a);
        for(int i=0; i<a.length; i++){
            System.out.println(a[i]);
        }
    }
}