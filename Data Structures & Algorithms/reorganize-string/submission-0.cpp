class Solution {
public:
    string reorganizeString(string s) {
        int n = s.length();

        map<char, int> mp;
        for(int i = 0 ; i < n ; i++) mp[s[i]]++;

        priority_queue<pair<int, char>> pq;
        for(auto it : mp) pq.push({it.second, it.first});

        string res = "";

        while(!pq.empty()) {
            auto it = pq.top();
            pq.pop();

            if(res.size() == 0) {
                res += it.second;
                if(it.first-1 != 0)pq.push({it.first-1, it.second});
            }
            else{
                if(it.second != res.back()){
                    res += it.second;
                    if(it.first-1 != 0)pq.push({it.first-1, it.second});
                }
                else if(pq.size() > 0) {
                    auto it2 = pq.top();
                    pq.pop();
                    res += it2.second;
                    if(it2.first-1 != 0)pq.push({it2.first-1, it2.second});
                    pq.push({it.first, it.second});
                }
                else return "";
            }
        }

        return res;
    }
};