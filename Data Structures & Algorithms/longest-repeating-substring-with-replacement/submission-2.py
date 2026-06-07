class Solution:
    def characterReplacement(self, s: str, k: int) -> int:
        n = len(s)
        freq = [0 for i in range(0, 256)]
        mx, l, r = 0, 0, 0
        res = 0

        while r < n:
            idx = ord(s[r])
            freq[idx] += 1
            mx = max(mx, freq[idx])

            while r-l+1 - mx > k:
                l_idx = ord(s[l])
                freq[l_idx] -= 1
                l += 1
            
            res = max(res, r-l+1)
            r += 1
        

        return res




