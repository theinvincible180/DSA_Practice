class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int n = nums.size();

        multiset<int> st;
        int idx = 0;

        while(idx < n) {
            if(idx < k){
                if(st.find(nums[idx]) != st.end()) return true;
                st.insert(nums[idx]);
            }
            else{
                if(st.find(nums[idx]) != st.end()) return true;

                st.insert(nums[idx]);
                st.erase(st.find(nums[idx-k]));
            }
            idx++;
        }

        return false;
    }
};