from collections import defaultdict
class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        n = len(nums)
        print(n)

        mp = defaultdict(int)
        ans = []

        for i in range(0, n):
            req = target - nums[i]

            if req in mp:
                ans.append(mp[req])
                ans.append(i)
            
            mp[nums[i]] = i
    
        return ans

