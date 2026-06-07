class Solution:
    def checkInclusion(self, s1: str, s2: str) -> bool:
        n = len(s1)
        m = len(s2)

        if m < n:
            return False

        freq_s1 = [0 for i in range(0, 256)]
        freq_s2 = [0 for i in range(0, 256)]

        for i in range(0, n):
            idx1 = ord(s1[i])
            freq_s1[idx1] += 1
            
            idx2 = ord(s2[i])
            freq_s2[idx2] += 1

        if freq_s1 == freq_s2:
            return True

        for i in range(n, m):
            idx1 = ord(s2[i])
            freq_s2[idx1] += 1
            idx2 = ord(s2[i-n])
            freq_s2[idx2] -= 1

            if freq_s1 == freq_s2:
                return True

        return False 
