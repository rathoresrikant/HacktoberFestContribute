class Solution {
public:
    void rotateby90(vector<vector<int>>& mat, int n) {
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                swap(mat[i][j], mat[j][i]);
            }
        }

        for (int i = 0; i < n; i++) {
            int low = 0, high = n - 1;
            while (low < high) {
                swap(mat[low][i], mat[high][i]);
                low++;
                high--;
            }
        }
    }
};
