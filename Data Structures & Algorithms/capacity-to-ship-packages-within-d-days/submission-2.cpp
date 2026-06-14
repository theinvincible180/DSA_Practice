class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int n = weights.size();
        int low = *max_element(weights.begin(), weights.end());
        int high = accumulate(weights.begin(), weights.end(), 0);
        int minWeight = INT_MAX;

        while(low <= high) {
            int mid = low + (high-low) / 2;
            int totalDays = 0;
            int sum = 0;

            for(int i = 0 ; i < n ; i++) {
                sum += weights[i];

                if(sum > mid) {
                    sum = weights[i];
                    totalDays++;
                }
            }
            if(sum > 0) totalDays++;

            if(totalDays <= days){
                minWeight = mid;
                high = mid-1;
            }
            else low = mid+1;
        }

        return minWeight;
    }
};