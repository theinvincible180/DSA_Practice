class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();

        // if(n == 1) return nums[0];

        // int l = 0 , r = 0;
        int sum = 0, mx = INT_MIN;

        for(int i = 0 ; i < n ; i++){
            sum = max(nums[i], sum + nums[i]);
            // if(sum < 0) sum = nums[i];

            mx = max(sum , mx);
        }

        return mx;
    }
};
