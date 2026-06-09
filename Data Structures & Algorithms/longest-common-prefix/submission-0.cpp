class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n = strs.size();

        if(n == 1) return strs[0];
        sort(strs.begin(), strs.end());

        int sz = min(strs[0].size(), strs[n-1].size());
        int len = 0;

        for(int i = 0 ; i < sz ; i++){
            if(strs[0][i] == strs[n-1][i]) len++;
            else break;
        }

        return strs[0].substr(0, len);
    }
};