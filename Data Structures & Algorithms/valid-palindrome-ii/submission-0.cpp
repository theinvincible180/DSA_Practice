class Solution {
public:
    bool isPalindrome(string& s, int l, int r) {
        while(l <= r){
            if(s[l] != s[r]) return false;
            l++;
            r--;
        }

        return true;
    }
    bool validPalindrome(string s) {
        int n = s.length();

        if(isPalindrome(s, 0, n-1)) return true;

        int l = 0 , r = n-1;

        while(l <= r) {
            if(s[l] != s[r]) {
                return isPalindrome(s, l+1, r) || isPalindrome(s, l, r-1);
            }
            l++;
            r--;
        }

        return false;
    }
};