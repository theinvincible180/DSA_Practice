class Solution {
public:
    void merge(vector<int>& nums, int low, int mid, int high){
        vector<int> left, right;
        for(int i = low ; i <= mid ; i++) left.push_back(nums[i]);
        for(int i = mid+1 ; i <= high ; i++) right.push_back(nums[i]);

        int i = 0, j = 0, k = low;
        while(i < left.size() && j < right.size()) {
            if(left[i] <= right[j]){
                nums[k] = left[i];
                i++;
                k++;
            }
            else{
                nums[k] = right[j];
                j++;
                k++;
            }
        }

        while(i < left.size()){
            nums[k] = left[i];
            i++;
            k++;
        }

        while(j < right.size()) {
            nums[k] = right[j];
            j++;
            k++;
        }
    }
    void mergeSort(vector<int>& nums, int low, int high){
        if(low >= high) return;

        int mid = low + (high-low)/2;
        mergeSort(nums, low, mid);
        mergeSort(nums, mid+1, high);
        merge(nums, low, mid, high);
    }
    vector<int> sortArray(vector<int>& nums) {
        int n = nums.size();

        mergeSort(nums, 0, n-1);
        return nums;
    }
};