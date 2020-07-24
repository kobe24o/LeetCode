class Solution:
    def divisorGame(self, N: int) -> bool:
        if N == 1:
            return False
        dp = [False]*(N+1)
        dp[1] = False
        dp[2] = True
        for i in range(1, N+1):
            for j in range(1, i):
                if i%j == 0 and not dp[i-j]:
                    dp[i] = True
        return dp[N]