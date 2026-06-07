class Solution:

    def encode(self, strs: List[str]) -> str:
        s = ""
        n = len(strs)

        if n == 0:
            return ""
        
        for i in range(0, len(strs)):
            s += strs[i] + "-"
         
        return s

    def decode(self, s: str) -> List[str]:
        res = []

        n = len(s)
        temp = ""

        if n == 0:
            return []

        for i in range(0, n-1):
            if s[i] != '-':
                temp += s[i]
            
            else:
                res.append(temp)
                temp = ""
            
        res.append(temp)
        return res
