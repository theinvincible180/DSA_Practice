from collections import defaultdict
class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        mp = defaultdict(list)
        n = len(strs)

        for i in range(0, n):
            sorted_word = tuple(sorted(strs[i]));
            mp[sorted_word].append(strs[i]);
            
        matrix = []

        for value in mp.values():
            matrix.append(value)

        return matrix
        