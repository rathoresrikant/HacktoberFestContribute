class counting_sort{
 	static void sort(int a[],int min,int max){
		int n = a.length;
		int count[] = new int[max-min+1];
		for(int i=0; i<max-min+1; i++)
			count[i] = 0;

		for(int i=0;i<n;i++)
			count[a[i]-min]++;
		
		int p=0;
		for(int i=0; i<max-min+1; i++)
			if(count[i]>0)
				for(int j=0; j<count[i]; j++)
					a[p++]=min+i;
	}

	public static void main(String args[]){
		int a[] = {6,0,7,8,9,5,6,4,6,3};
		int max = 9;
		int min = 0;
		sort(a, min, max);
		for(int i=0; i<a.length; i++)
			System.out.println(a[i]);
	}
}
