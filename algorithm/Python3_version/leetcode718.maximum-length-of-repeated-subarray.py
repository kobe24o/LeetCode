class Solution:
    def findLength(self, A: List[int], B: List[int]) -> int:
        m = len(A) 
        n = len(B)
        maxlen = 0
        dp = [[0]*(n+1) for _ in range(m+1)]
        for i in range(1,m+1):
            for j in range(1, n+1):
                if A[i-1] == B[j-1]:
                    dp[i][j] = dp[i-1][j-1]+1
                maxlen = max(maxlen, dp[i][j])
        return maxlen