class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int n = nums.size();

        int l = 0 , h = 0;

        while(h < n){
            if(nums[h] != val){
                nums[l] = nums[h];
                l++;
            }
            h++;
        }

        return l;
    }
};