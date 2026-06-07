class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> freqs(26, 0);
        vector<int> freqt(26, 0);

        for(int i = 0 ; i < s.length() ; i++) freqs[s[i] - 'a']++;
        for(int i = 0 ; i < t.length() ; i++) freqt[t[i] - 'a']++;

        return freqs == freqt;
    }
};
