class Solution {
public:
    bool searchMatrix(vector<vector<int>>& mat, int x) {
        int n = mat.size();
        int m = mat[0].size();

        int low = 0, high = n-1;
        int lowerRow = n;
        while(low <= high) {
            int mid = low + (high-low)/2;

            if(mat[mid][m-1] >= x) {
                lowerRow = mid;
                high = mid-1;
            }
            else{ 
                low = mid+1;
            }
        }

        if(lowerRow == n) return false;

        low = 0, high = m-1;
        while(low <= high) {
            int mid = low + (high-low) / 2;

            if(mat[lowerRow][mid] == x) return true;
            else if(mat[lowerRow][mid] > x) high = mid-1;
            else low = mid+1;
        }

        return false;
    }
};
