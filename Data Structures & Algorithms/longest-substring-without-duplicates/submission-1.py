class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        n = len(s)

        l, r = 0, 0
        freq = [0 for i in range(0, 256)]
        ans = 0

        while r < n and l <= r:
            idx = ord(s[r])
            freq[idx] += 1

            while freq[idx] > 1 and l <= r:
                lidx = ord(s[l])
                freq[lidx] -= 1
                l += 1

            ans = max(ans, r-l+1)
            r += 1
        
        return ans


