class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();

        int low = 0, high = 0;
        int sum = 0, len = n+1;

        while(high < n) {
            sum += nums[high];

            while(sum >= target) {
                len = min(len, high-low+1);
                sum -= nums[low];
                low++;
            }

            high++;
        }

        return len == n+1 ? 0 : len;
    }
};