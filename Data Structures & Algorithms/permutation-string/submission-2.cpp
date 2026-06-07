class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n = s1.length();
        int m = s2.length();
        int left = 0, right = 0;

        multiset<char> st1(s1.begin(), s1.end());
        multiset<char> st2;

        while(right < m){
            if(right < n)st2.insert(s2[right]);
            else{
                st2.insert(s2[right]);
                st2.erase(st2.find(s2[left]));
                left++;
            }
            right++;
            if(st1 == st2) return true;
        }

        return false;
    }
};
