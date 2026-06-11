class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mn = prices[0];
        int n = prices.size();
        int mxProfit = 0;

        for(int i = 0 ; i < n ; i++) {
            if(prices[i] < mn)mn = prices[i];

            mxProfit = max(mxProfit, prices[i]-mn);
        }

        return mxProfit;
    }
};
