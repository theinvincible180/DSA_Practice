class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int n = arr.size();
        priority_queue<pair<int, int>> pq;

        for(int i = 0 ; i < n ; i++){
            int diff = abs(x-arr[i]);

            pq.push({diff, i});

            if(pq.size() > k) pq.pop();
        }

        vector<int> res;
        while(!pq.empty()){
            auto it = pq.top();
            int idx = it.second;
            int num = arr[idx];

            pq.pop();

            res.push_back(num);
        }
        sort(res.begin(), res.end());
        return res;
    }
};