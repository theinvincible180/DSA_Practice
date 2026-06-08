class Solution {
public:
    bool isPalindrome(string s) {
        int n = s.length();

        string temp;
        for(int i = 0 ; i < n ; i++){
            if(s[i] >= 'a' && s[i] <= 'z') temp += s[i];
            else if(s[i] >= 'A' && s[i] <= 'Z') temp += s[i] + 32;
            else if(s[i] >= '0' && s[i] <= '9') temp += s[i];
        }

        string rev = temp;
        reverse(rev.begin(), rev.end());

        cout << temp;

        return rev == temp;
    }
};
