class Solution {
public:
    int helper(string& s, int idx, vector<int>& dp){
        int n = s.length();
        if(idx == n) return 1;
        if(s[idx] == '0') return 0;

        if(dp[idx] != -1) return dp[idx];

        int ways = helper(s, idx+1, dp);

        if(idx + 1 < n){
            int num = (s[idx] - '0')*10 + (s[idx+1]-'0');
            if(num >= 10 && num <= 26) {
                ways += helper(s, idx+2, dp);
            }
        }

        return dp[idx] = ways;
    }
    int numDecodings(string s) {
        int n = s.length();
        vector<int> dp(n+1, -1);

        return helper(s, 0, dp);
    }
};
