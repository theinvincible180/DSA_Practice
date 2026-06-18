class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        int n = points.size();
        priority_queue<pair<double, vector<int>>> pq;

        for(int i = 0 ; i < n ; i++) {
            int x = points[i][0];
            int y = points[i][1];

            int total = x*x + y*y;

            double dist = sqrt(total);

            pq.push({dist, points[i]});

            if(pq.size() > k) pq.pop();
        }

        vector<vector<int>> result;
        while(!pq.empty()) {
            vector<int> point = pq.top().second;
            result.push_back(point);
            pq.pop();
        }

        return result;
    }
};
