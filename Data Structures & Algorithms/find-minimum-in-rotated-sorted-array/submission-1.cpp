class Solution {
public:
    int findMin(vector<int> &nums) {
        int n = nums.size();

        int low = 0, high = n-1;
        int res = INT_MAX;

        while(low <= high) {
            if(nums[low] <= nums[high]){
                res = min(nums[low], res);
                break;
            }
            int mid = low + (high-low) / 2;
            res = min(res, nums[mid]);

            if(nums[mid] >= nums[low]){
                low = mid+1;
            }
            else{
                high = mid-1;
            }
        }

        return res;
    }
};
