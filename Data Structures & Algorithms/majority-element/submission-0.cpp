class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        int num = nums[0], cnt = 1;

        for(int i = 1 ; i < n ; i++){
            if(nums[i] == num)cnt++;
            else{
                cnt--;
                if(cnt < 0){
                    num = nums[i];
                    cnt = 1;
                }
            }
        }

        int cnt2 = 0;
        for(int i = 0 ; i < n ; i++){
            if(nums[i] == num)cnt2++;
        }

        return cnt2 > n/2 ? num : 0;
    }
};