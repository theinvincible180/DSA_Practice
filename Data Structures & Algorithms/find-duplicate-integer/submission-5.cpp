class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        unordered_set<int> seen;
        int n = nums.size();

        for(int i = 0 ; i < n ; i++){
            if(seen.find(nums[i]) != seen.end()) return nums[i];

            seen.insert(nums[i]);
        }

        return -1;
    }
};
