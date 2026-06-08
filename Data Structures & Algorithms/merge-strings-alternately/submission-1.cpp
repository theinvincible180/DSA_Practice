class Solution {
public:
    string mergeAlternately(string s, string t) {
        int n = s.length();
        int m = t.length();

        int idx1 = 0 , idx2 = 0;
        string temp;

        while(idx1 < n && idx2 < m) {
            temp += s[idx1];
            temp += t[idx2];

            idx1++;
            idx2++;
        }

        while(idx1 < n){
            temp += s[idx1];
            idx1++;
        }

        while(idx2 < m){
            temp += t[idx2];
            idx2++;
        }

        return temp;
    }
};