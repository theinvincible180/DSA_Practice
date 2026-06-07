class Solution:
    def maxProfit(self, nums: List[int]) -> int:
        n = len(nums)
        mn, mx, x = 101, -1, 0
        ans = 0

        while x < n:
            if nums[x] < mn:
                mn = nums[x]
                mx = nums[x]
            
            if nums[x] > mx:
                mx = nums[x]
                ans = max(ans, mx-mn)


            x += 1
        
        return ans

        