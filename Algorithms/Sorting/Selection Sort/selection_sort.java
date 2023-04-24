class selection_sort{
	static void sort(int a[]){
		int n = a.length;
		int min = 0, temp = 0;
		for(int i=0;i<n;i++){
			min = i;
			for(int j=i+1;j<n;j++)
				if(a[j] < a[min])
					min = j;
			temp = a[i];
			a[i] = a[min];
			a[min] = temp;
		}
	}
	
	public static void main(String args[]){
		int a[] = {4,5,6,1,2,3,4,8,1};
		sort(a);
		for(int i=0;i<a.length;i++)
			System.out.println(a[i]);
	}
}
