class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.length();

        int low = 0, high = 0;
        int res = 0;
        int mxFreq = 0;
        map<char, int> mp;

        while(high < n) {
            mp[s[high]]++;
            mxFreq = max(mxFreq, mp[s[high]]);

            while(high-low+1 - mxFreq > k) {
                mp[s[low]]--;
                low++;
            }

            res = max(res, high-low+1);
            high++;
        }

        return res;

    }
};
