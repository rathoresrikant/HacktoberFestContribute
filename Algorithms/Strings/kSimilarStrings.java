/*
Strings A and B are K-similar (for some non-negative integer K) if we can swap 
the positions of two letters in A exactly K times so that the resulting string 
equals B.
Given two anagrams A and B, return the smallest K for which A and B are K-similar.
*/



class Solution {
    public int kSimilarity(String A, String B) {
      return DFS(A.toCharArray(), B.toCharArray(), 0, 0);
    }
    
    public int DFS(char[]  A, char[] B, int i, int count) {
        int result = Integer.MAX_VALUE;

        if(i == A.length - 1) {
            if(Arrays.equals(A, B)) return count;
            else return result;
        }
        
        if(A[i] == B[i]) return DFS(A, B, i + 1, count);
        
        for(int j = i + 1; j < B.length; j++) {
            if(A[i] == B[j] && B[j] != A[j]) {
                swap(B, i, j); // Let's fix B, we can also fix A by changing above condition to A[j] == B[i]
                result = Math.min(result, DFS(A, B, i + 1, count + 1));
                swap(B, i, j);
            }
        }
        
        return result;
    }
   
    public void swap(char[] arr, int i, int j) {
        char temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
}