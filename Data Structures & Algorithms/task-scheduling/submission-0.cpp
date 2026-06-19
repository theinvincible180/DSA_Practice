class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int sz = tasks.size();

        map<char, int> mp;
        for(int i = 0 ; i < sz ; i++) mp[tasks[i]]++;

        priority_queue<int> pq;
        for(auto it : mp) pq.push(it.second);

        int time = 0;
        queue<pair<int, int>> qt;

        while(!qt.empty() || !pq.empty()) {
            time += 1;
            if(!pq.empty()){
                int num = pq.top();
                pq.pop();

                num = num - 1;

                if(num != 0) {
                    int nxtTime = time + n;
                    qt.push({num, nxtTime});
                }
            }

            while(qt.front().second == time){
                auto it = qt.front();
                qt.pop();

                pq.push(it.first);
            }
        }

        return time;
    }
};
