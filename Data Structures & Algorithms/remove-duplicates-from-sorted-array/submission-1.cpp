class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        int l = 0, h = 1;

        while(l < n && h < n) {
            if(nums[l] != nums[h]){
                nums[l+1] = nums[h];
                l++;
            }
            h++;
        }

        return l+1;
    }
};