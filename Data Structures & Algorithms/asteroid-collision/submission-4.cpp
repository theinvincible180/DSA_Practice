class Solution {
   public:
    vector<int> asteroidCollision(vector<int>& arr) {
        int n = arr.size();

        stack<int> st;

        for (int i = 0; i < n; i++) {
            if (st.empty() || arr[i] > 0)
                st.push(arr[i]);
            else {
                if (st.top() < 0)
                    st.push(arr[i]);
                else {
                    bool destroyed = false;
                    while (!st.empty() && st.top() > 0) {
                        int num = st.top();
                        if (abs(num) > abs(arr[i])) {
                            destroyed = true;
                            break;
                        } else if (abs(num) == abs(arr[i])) {
                            destroyed = true;
                            st.pop();
                            break;
                        } else {
                            st.pop();
                        }
                    }

                    if (!destroyed) st.push(arr[i]);
                }
            }
        }

        vector<int> res;
        while (!st.empty()) {
            int ast = st.top();
            st.pop();
            res.push_back(ast);
        }

        reverse(res.begin(), res.end());
        return res;
    }
};
