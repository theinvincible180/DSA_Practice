class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.length();
        int m = t.length();

        int l = 0, r = 0;
        int hash[256] = {0}; 
        int cnt = 0;
        int mn = INT_MAX;
        int idx = -1;

        for(int i = 0 ; i < m ; i++) hash[t[i]]++;

        while(r < n) {
            if(hash[s[r]] > 0) cnt++;
            hash[s[r]]--;

            while(cnt == m){
                if(r-l+1 < mn){
                    mn = r-l+1;
                    idx = l;
                }
                
                hash[s[l]]++;
                if(hash[s[l]] > 0)cnt -= 1;
                l++;
            }
            r++;
        }

        return idx == -1 ? "" : s.substr(idx, mn);
    }
};
