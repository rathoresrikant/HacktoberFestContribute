public class RODCutting {

	public static void main(String[] args) {
		//here size of rod 8 unit
		//			 1 ,2 ,3 ,4  ,5  ,6  ,7  ,8     price of these units are as follows... 
		int arr[] = {1 ,3 ,7 ,8 ,12, 15, 16, 17};
		int size = arr.length;
		cutrod(arr,size);
	}
	public static void cutrod(int price[],int n){
		int val[] = new int [n+1];
		val[0] = 0;
		for(int i=1; i<=n ; i++)
		{
			int Max_val = -1;
			for(int j = 0; j<i ; j++)
			{
				Max_val = Math.max(Max_val, price[j] + val[i-j-1]);
				val[i] = Max_val;
			}
		}
		System.out.println("Maximum obtimized rod profit is  "+val[n]);
	}
}
