class Solution:
    def numRollsToTarget(self, d: int, f: int, target: int) -> int:
        dp = [[0 for i in range(target+1)] for i in range(d+1)]
        dp[0][0] = 1
        for i in range(1,d+1):
            for j in range(0, target):
                if dp[i-1][j]==0:
                    continue
                for k in range(1, f+1):
                    if j+k <= target:
                        dp[i][j+k] = (dp[i][j+k]+dp[i-1][j])%1000000007
        return dp[d][target]