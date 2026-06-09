class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return;
        int low = 0, high = n-1, k = 0;

        while(k <= high) {
            if(nums[k] == 0){
                swap(nums[low++], nums[k++]);
            }
            else if(nums[k] == 1){
                k++;
            }
            else{
                swap(nums[k], nums[high--]);
            }
        }
    }
};