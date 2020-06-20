class Solution:
    def isMatch(self, s: str, p: str) -> bool:
        m, n = len(s), len(p)
        dp = [[0]*(n+1) for _ in range(m+1)]
        dp[0][0] = 1
        for i in range(m+1):
            for j in range(1,n+1):
                if p[j-1]=='*':
                    dp[i][j] |= dp[i][j-1] | (dp[i-1][j] if i>0 else 0)
                else:
                    if i>0 and (s[i-1]==p[j-1] or p[j-1]=='?'):
                        dp[i][j] |= dp[i-1][j-1]
        return True if dp[m][n] else False