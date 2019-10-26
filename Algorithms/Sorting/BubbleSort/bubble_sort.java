class bubble_sort{
	static void sort(int a[]){
		int n = a.length;
		for(int i=0;i<n;i++){
			int temp = 0;
			int count = 0;
			for(int j=0;j<n-1;j++){
				if(a[j] > a[j+1]){
					count++;
					temp = a[j];
					a[j] = a[j+1];
					a[j+1] = temp;
				}
			}
			if(count == 0)
				break;
		}
	}

	public static void main(String args[]){
		int a[] = {2,3,5,6,7,1,8,6,4,8};
		sort(a);
		for(int i=0;i<a.length;i++)
			System.out.println(a[i]);
	}
} 
	

