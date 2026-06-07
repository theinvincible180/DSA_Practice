class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();

        int l = 0 , r = 0;
        string str = "";

        while(l < n &&  r < m){
            str = str + word1[l] + word2[r];
            l++;
            r++;
        }

        str += word1.substr(l);
        str += word2.substr(r);

        return str;
    }
};