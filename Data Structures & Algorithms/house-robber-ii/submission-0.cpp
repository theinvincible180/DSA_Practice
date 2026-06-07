class Solution {
public:
    int helper(vector<int>& nums, int idx, int limit, vector<int>& dp){
        if(idx < limit)return 0;

        if(dp[idx] != -1) return dp[idx];

        int notpick = helper(nums, idx-1, limit, dp);

        int pick = nums[idx] + helper(nums, idx-2, limit, dp);

        return dp[idx] = max(pick, notpick);
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp1(n, -1), dp2(n, -1);

        return max(nums[n-1] + helper(nums, n-3, 1, dp1), helper(nums, n-2, 0, dp2));
    }
};
