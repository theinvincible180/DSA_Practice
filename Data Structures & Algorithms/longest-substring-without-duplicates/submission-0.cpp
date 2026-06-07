class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();

        int left = 0, right = 0;
        set <char> st;
        int ans = 0;

        while(right < n) {
            while(st.find(s[right]) != st.end()){
                st.erase(s[left]);
                left++;
            }

            st.insert(s[right]);
            ans = max(ans, right-left+1);
            right++;
        }

        return ans;
    }
};
