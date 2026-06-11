class Solution {
public:
    int lower_bound(vector<int>& arr, int x){
        int n = arr.size();
        int low = 0, high = n-1;
        int idx = n;

        while(low <= high) {
            int mid = low + (high-low)/2;

            if(arr[mid] >= x){
                idx = mid;
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }

        return idx == n ? n-1 : idx;
    }
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int n = arr.size();

        int idx = lower_bound(arr, x);

        cout << idx << endl;

        int idx1 = idx, idx2 = idx-1;
        vector<int> res;

        while(idx2 >= 0 && idx1 < n && res.size() < k) {
            if(abs(x-arr[idx2]) <= abs(x-arr[idx1])) {
                res.push_back(arr[idx2]);
                idx2--;
            }
            else{
                res.push_back(arr[idx1]);
                idx1++;
            }
        }

        if(res.size() < k) {
            while(idx2 >= 0 && res.size() < k) {
                res.push_back(arr[idx2]);
                idx2--;
            }

            while(idx1 < n && res.size() < k) {
                res.push_back(arr[idx1]);
                idx1++;
            }
        }

        sort(res.begin(), res.end());
        return res;
    }
};