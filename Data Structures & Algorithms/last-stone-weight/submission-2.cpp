class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        int n = stones.size();
        priority_queue<int> pq;

        for(int i = 0 ; i < n ; i++) pq.push(stones[i]);

        while(pq.size() > 1) {
            int stone1 = pq.top();
            pq.pop();

            int stone2 = pq.top();
            pq.pop();

            if(stone1 > stone2) pq.push(stone1 - stone2);
            else if(stone2 > stone1) pq.push(stone2 - stone1);
            else continue;
        }

        return pq.empty() ? 0 : pq.top();
    }
};
