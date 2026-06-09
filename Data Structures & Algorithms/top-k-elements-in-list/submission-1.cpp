class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();

        map<int, int> mp;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        for(int i = 0 ; i < n ; i++) mp[nums[i]]++;

        for(auto it : mp) {
            pq.push({it.second, it.first});

            if(pq.size() > k) pq.pop();
        }

        vector<int> res;

        while(!pq.empty()) {
            auto it = pq.top();
            pq.pop();

            res.push_back(it.second);
        }

        return res;
    } 
};
