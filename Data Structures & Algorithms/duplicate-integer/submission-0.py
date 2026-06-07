class Solution:
    def hasDuplicate(self, nums: List[int]) -> bool:
        new_list = set(nums)

        if len(nums) == len(new_list):
            return False

        return True
        