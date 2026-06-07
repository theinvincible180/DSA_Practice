class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1, high = *max_element(piles.begin(), piles.end());
        int ans;

        while(low <= high) {
            int mid = low + (high-low)/2;
            int cnt = 0;
            
            for(auto it : piles) {
                cnt += it/mid + (it%mid == 0 ? 0 : 1);
            }

            if(cnt <= h) {
                ans = mid;
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }

        return ans;
    }
};
