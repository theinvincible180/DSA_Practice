class Solution:
    def maxArea(self, nums: List[int]) -> int:
        n = len(nums)
        l, r = 0, n-1

        mx = -1

        while l < r:
            mx = max(mx, min(nums[l], nums[r]) * (r-l))

            if nums[l] < nums[r]:
                l += 1
            
            elif nums[r] < nums[l]:
                r -= 1
            
            else: 
                l += 1
                r -= 1
        

        return mx
