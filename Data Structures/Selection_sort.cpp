/* algorithm for selection sorting. Process :-
	1. finds index of max in arr.
	2. swaps it with index 0.
	3. finds max from arr[1] to arr[size].
	4. swaps it with index 1.
	5. and continues it upto finding max from arr[size-2] to arr[size-1].
	NOTE: SORTING IS BEING DONE IN DESCENDING ORDER!! */
#include<bits/stdc++.h>
using namespace std;
int selection_sort(int* arr, int size)
{
	int max, max_ind, i;
	for( i=0 ; i<size ; i++)
	{
		max = arr[i];//take the first element from the indices i to n to be max
		max_ind = i;//taking index of the first element from i to n
		for(int j=i; j<size ; j++ )
		{
			if(arr[j]>max)//from i to n,if any index has value greater than max,store it in max,and store the index in max_ind
			{
				max = arr[j];
				max_ind = j;
			}
		}
		arr[max_ind] = arr[i];//finally,arr[max_ind] has the greatest index from i to n...
		arr[i] = max;//by the above two statements,we swap the values in arr[i] and arr[max_ind] so that the greatest element is brought to front of the sub-list.
	}
}
int main()
{
	int a[]={1,4,2,5,6};
	selection_sort(a,5);
	for(int i=0;i<5;i++)
	{
		cout<<a[i]<<" ";
	}
	return(0);
}

/* HOW TO USE : 1. Copy the snippet in your code.
				2. Call selection_sort(array_name, array_size);
*/
