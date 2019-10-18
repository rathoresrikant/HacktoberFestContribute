public class ArrayReverse {
    public static void reverse(int a[]){
        int tmp;
        for(int i=0; i<a.length/2; i++){
            tmp = a[i];
            a[i] = a[a.length-i-1];
            a[a.length-i-1] = tmp;
        }
    }

    public static void main(String args[]){
        int a[] = {1,2,3,4,5,6,7};
        reverse(a);
        for(int i=0; i<a.length; i++){
            System.out.println(a[i]);
        }
    }
}