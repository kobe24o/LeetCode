class Solution:
    def isInterleave(self, s1: str, s2: str, s3: str) -> bool:
        m, n = len(s1), len(s2)
        if m+n != len(s3):
            return False;
        dp = [[0]*(n+1) for _ in range(m+1)]
        dp[0][0] = 1
        for i in range(m):
            if s1[i] == s3[i]:
                dp[i+1][0] = 1
            else:
                break
        for i in range(n):
            if s2[i] == s3[i]:
                dp[0][i+1] = 1
            else:
                break
        for i in range(1,m+1):
            for j in range(1,n+1):
                k = i+j
                if s1[i-1] == s3[k-1]:
                    dp[i][j] |= dp[i-1][j]
                if s2[j-1] == s3[k-1]:
                    dp[i][j] |= dp[i][j-1]
        return True if dp[m][n] else False