class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int n = nums.size();

        int low = 0 , high = 0;
        set<int> st;
        
        while(high < n) {
            if(high-low > k) {
                st.erase(nums[low]);
                low++;
            }

            if(st.count(nums[high]) > 0) return true;

            st.insert(nums[high]);
            high++;       
        }

        return false;
    }
};