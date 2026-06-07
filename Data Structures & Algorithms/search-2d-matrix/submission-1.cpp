class Solution {
public:
    bool searchMatrix(vector<vector<int>>& mat, int target) {
        int n = mat.size();
        int m = mat[0].size();

        int low = 0, high = n-1;

        while(low <= high) {
            int mid = low + (high-low) / 2;

            if(mat[mid][m-1] == target) return true;
            else if(mat[mid][m-1] > target) high = mid - 1;
            else low = mid + 1;
        }

        if(low >= n) return false;
        // if(high < 0) return false;

        vector<int> row = mat[low];
        low = 0, high = m-1;

        while(low <= high) {
            int mid = low + (high-low) / 2;

            if(row[mid] == target) return true;
            else if(row[mid] > target) high = mid - 1;
            else low = mid + 1;
        }

        return false;
    }
};
