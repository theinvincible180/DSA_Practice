class Solution {
public:
    int helper(vector<int>& cost, int idx, int n, vector<int>& dp){
        if(idx >= n) return 0;

        if(dp[idx] != -1) return dp[idx];

        return dp[idx] = cost[idx] + min(helper(cost, idx+1, n, dp), helper(cost, idx+2, n, dp));
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> dp(n+1, -1);

        return min(helper(cost, 0, n, dp), helper(cost, 1, n, dp));
    }
};
