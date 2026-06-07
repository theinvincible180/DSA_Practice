class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        mp = {}
        freq = [[] for i in range(len(nums)+1)]

        for n in nums:
            mp[n] = 1 + mp.get(n, 0);

        for n, c in mp.items():
            freq[c].append(n)
        
        res = []

        for i in range(len(freq)-1, 0, -1):
            for n in freq[i]:
                res.append(n)
                if len(res) == k:
                    return res
        
        return []