class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.length();

        int left = 0, right = 0;
        int maxf = 0, res = 0;
        map<char, int> mp;

        char ch = s[0];

        while(right < n) {
            mp[s[right]]++;
            maxf = max(maxf, mp[s[right]]);

            while(right-left+1 - maxf > k){
                mp[s[left]]--;
                left++;
            }

            res = max(res, right-left+1);
            right++;
        }

        return res;
    }
};
