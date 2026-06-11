class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();

        int low = 0, high = 0;
        int res = 0;
        map<char, int> mp;

        while(high < n) {
            mp[s[high]]++;

            while(mp[s[high]] > 1){
                mp[s[low]]--;
                low++;
            }

            res = max(res, high-low+1);
            high++;
        }

        return res;
    }
};
