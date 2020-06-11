class Solution:
    def findLongestWord(self, s: str, d: List[str]) -> str:
        ans = ""
        n = len(d)
        m = len(s)
        for i in range(n):
            j = k = 0
            while j < m and k < len(d[i]):
                if s[j]==d[i][k]:
                    k += 1
                j += 1
            if k==len(d[i]):
                if (len(d[i]) > len(ans)) or (len(d[i])==len(ans) and d[i] < ans):
                    ans = d[i]
        return ans