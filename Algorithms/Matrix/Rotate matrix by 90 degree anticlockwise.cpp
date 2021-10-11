//efficient solution
//Approach:-
//1. Transpose the whole matrix
//2. Reverse individual columns using two pointers approach

class Solution
{   
    public:
    //Function to rotate matrix anticlockwise by 90 degrees.
    void rotateby90(vector<vector<int> >& mat, int n) 
    { 
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                swap(mat[i][j],mat[j][i]);  //transpose of a matrix
            }
        }
        
        for(int i=0;i<n;i++){
            int low = 0,high=n-1;
            while(low<high){
                swap(mat[low][i],mat[high][i]); //reverse individual columns
                low++;
                high--;
            }
        }
    } 
};
