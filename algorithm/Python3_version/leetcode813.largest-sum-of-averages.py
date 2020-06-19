class Solution:
    def largestSumOfAverages(self, A: List[int], K: int) -> float:
        n = len(A)
        dp = [[0.0]*(K+1) for _ in range(n)]
        for i in range(1,n):
            A[i] += A[i-1]
        for i in range(n-K+1):
            dp[i][1] = A[i]/(i+1)
        for k in range(2, K+1):
            for j in range(k-1, n-(K-k)):
                for i in range(j):
                    dp[j][k] = max(dp[j][k], dp[i][k-1]+(A[j]-A[i])/(j-i))
        return dp[n-1][K]