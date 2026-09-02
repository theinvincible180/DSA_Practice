class Solution {
public:
    void helper(vector<int>& nums, int n, int idx, vector<int> temp, vector<vector<int>>& result){
        if(idx == n){
            result.push_back(temp);
            return;
        }

        temp.push_back(nums[idx]);
        helper(nums, n, idx+1, temp, result);
        temp.pop_back();
        helper(nums,n, idx+1, temp, result);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> result;

        helper(nums, n, 0, {}, result);

        return result;
    }
};
