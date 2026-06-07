class Solution {
public:
    int shipWithinDays(vector<int>& nums, int days) {
        int n = nums.size();

        int low = *max_element(nums.begin(), nums.end()), high = accumulate(nums.begin(), nums.end(), 0);
        int ans = 0;

        while(low <= high) {
            int mid = low + (high-low) / 2;

            int cnt = 1, temp = 0;

            for(auto it : nums) {
                if(temp + it > mid) {
                    cnt++;
                    temp = 0;
                }
                temp += it;
            }

            // if(temp >= mid)cnt++;

            if(cnt <= days){
                ans = mid;
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }

        return ans;
    }
};