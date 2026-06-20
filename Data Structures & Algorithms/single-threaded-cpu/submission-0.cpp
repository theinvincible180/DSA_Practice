class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        long long time = 0;
        int idx = 0;
        int n = tasks.size();

        vector<vector<int>> sortedTasks;
        for(int i = 0 ; i < n ; i++) sortedTasks.push_back({tasks[i][0], tasks[i][1], i});
        sort(sortedTasks.begin(), sortedTasks.end());
         
        vector<int> result;

        while(!pq.empty() || idx < n) {
            if(pq.empty() && time < sortedTasks[idx][0]) time = sortedTasks[idx][0];

            while(idx < n && sortedTasks[idx][0] <= time) {
                pq.push({sortedTasks[idx][1], sortedTasks[idx][2]});
                idx++;
            }

            auto it = pq.top();
            pq.pop();

            time += it.first;
            result.push_back(it.second);
        }

        return result;
    }
};