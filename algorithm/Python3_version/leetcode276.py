class Solution:
    def numWays(self, n: int, k: int) -> int:
        if n==0 or k==0:
            return 0
        dp = [0]*n
        if n >= 1:
            dp[0] = k
        if n >= 2:
            dp[1] = k**2
        for i in range(2, n):
            dp[i] = (dp[i-1]+dp[i-2])*(k-1)
        return dp[n-1]