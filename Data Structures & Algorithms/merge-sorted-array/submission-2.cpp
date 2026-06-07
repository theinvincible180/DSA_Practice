class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int idx = m+n-1, l = m-1, r = n-1;
        if(n == 0) return;

        while(r >= 0 ) {
            if(l >= 0 && nums1[l] >= nums2[r]){
                nums1[idx] = nums1[l];
                l--;
            }
            else{
                nums1[idx] = nums2[r];
                r--;
            }
            idx--;
        }
    }
};