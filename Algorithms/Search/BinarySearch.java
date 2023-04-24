public class BinarySearch {
    public static int binarySearch(int a[], int key){
        int left = 0;
        int right = a.length-1;
        int mid;
        while(left<=right){
            mid = (left+right)/2;
            if(a[mid]==key) return mid;
            if(a[mid]<key) left = mid+1;
            else right = mid-1;
        }
        return -1;
    }

    public static void main(String args[]){
        int a[] = {2,4,6,8,10,12,14,16,18,20};
        System.out.println(binarySearch(a, 5));
        System.out.println(binarySearch(a, 16));
    }
}