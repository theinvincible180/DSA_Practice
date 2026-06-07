class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();

        int mn = prices[0];
        int mx = 0;

        for(int i = 1 ; i < n ; i++){
            mx = max(mx, prices[i]-mn);
            mn = min(mn, prices[i]);
        }

        return mx;
    }
};
