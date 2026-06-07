class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int left = 0, right = 0;
        int sum = 0, res = n+1;

        while(right < n) {
            sum += nums[right];

            while(sum >= target) {
                sum -= nums[left];
                res = min(res, right - left + 1);
                left++;
            }

            // res = min(res, right - left + 1);
            right++;
        }
        res = min(res, right-left+1);

        return res == n+1 ? 0 : res;
    }
};