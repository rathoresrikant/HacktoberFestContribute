<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<  Program Rotation Count Of a Sorted Array     >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

/*Given a circularly sorted array of integers, find the minimum number of rotations performed on some sorted array to create this given array.
Assume there are no duplicates in the array and the rotation is in anti-clockwise direction

Input format:

First line of input will contain a number T = number of test cases. Each test case will contain 2 lines.
First line will contain a number N = number of elements in the array.
Next line will contain N space separated integers.
Complete the function int rotationCount(int array[], int size) which will receive the array and size of the array as input and return how many times the 
sorted array is rotated. Function should return 0 if the array is not rotated.

Output format:

Print one line of output for each test case with the minimum number of rotations for the given array.
  
Constraints:

1<= N <= 50
-1000 <= arr[i] <= 1000
  
Sample Input

2
6
15 18 3 4 6 12
6
1 2 3 4 5 6
  
Sample Output

2
0
*/
  
<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<    Solution Of Code   >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

int rotationCount(int a[], int size){
   int mn = *min_element(a,a+size);
    for (int i = 0; i < size; i++)
    {
        if(a[i] == mn){
            return i;
        }
    }
    return 0;
}
  
