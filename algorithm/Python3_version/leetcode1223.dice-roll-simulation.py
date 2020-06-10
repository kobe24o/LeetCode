class Solution:
    def dieSimulator(self, n: int, rollMax: List[int]) -> int:
        dp = [[[0 for i in range(16)] for i in range(6)] for i in range(n)]
        for j in range(6):
            dp[0][j][1] = 1
        for i in range(1,n):
            for j in range(6):
                for k in range(1,16):
                    if dp[i-1][j][k]==0:
                        continue
                    for nj in range(6):
                        if nj==j and k+1 <= rollMax[j]:
                            dp[i][nj][k+1] = (dp[i][nj][k+1]+dp[i-1][j][k])%1000000007
                        if nj!=j:
                            dp[i][nj][1] = (dp[i][nj][1]+dp[i-1][j][k])%1000000007;
        sum = 0
        for j in range(6):
            for k in range(1,16):
                sum = (sum+dp[n-1][j][k])%1000000007
        return sum