class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        n = len(nums)

        pre = []
        post = []

        pre.append(1)
        multiplier = 1
        for i in range(0, n-1):
            multiplier *= nums[i]
            pre.append(multiplier)
        
        multiplier = 1
        post.append(1)
        for i in range(n-1, 0, -1):
            multiplier *= nums[i]
            post.append(multiplier)
        post.reverse()

        print(pre)
        print(post)

        res = [0 for i in range(0, n)]
        for i in range(0, n):
            res[i] = pre[i]*post[i]
        

        return res
