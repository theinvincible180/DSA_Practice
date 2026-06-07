class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> res;
        int mx = 0;
        multiset<int> st;

        for(int i = 0 ; i < k ; i++){
            st.insert(nums[i]);
        }

        int num = *st.rbegin();
        res.push_back(num);

        for(int i = k ; i < n ; i++){
            st.erase(st.find(nums[i-k]));
            st.insert(nums[i]);

            num = *st.rbegin();
            res.push_back(num);
        }

        return res;
    }
};
