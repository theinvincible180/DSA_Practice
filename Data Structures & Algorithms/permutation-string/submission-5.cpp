class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n1 = s1.length(), n2 = s2.length();

        map<char, int> mp1;
        map<char, int> mp2;
        int idx = 0;

        for(; idx < n1 ; idx++){
            mp1[s1[idx]]++;
            mp2[s2[idx]]++;
        }

        if(mp1 == mp2) return true;

        for(; idx < n2 ; idx++) {
            mp2[s2[idx]]++;
            mp2[s2[idx-n1]]--;

            if(mp2[s2[idx-n1]] == 0)mp2.erase(s2[idx-n1]);

            if(mp1 == mp2) return true;
        }

        return false;
    }
};
