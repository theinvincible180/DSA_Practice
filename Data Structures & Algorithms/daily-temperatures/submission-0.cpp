class Solution {
   public:
    vector<int> dailyTemperatures(vector<int>& arr) {
        int n = arr.size();

        stack<pair<int, int>> st;
        vector<int> res(n, 0);

        for (int i = 0; i < n; i++) {
            if (st.empty() || st.top().first > arr[i]) st.push({arr[i], i});
            else {
                while(st.size() > 0 && st.top().first < arr[i]) {
                    int idx = st.top().second;
                    st.pop();
                    res[idx] = i-idx;
                }
                st.push({arr[i], i});
            }
        }

        return res;
    }
};
