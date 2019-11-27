class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& A, int K) {
        int i, j, n = A.size(), Max;
        int dp[n+1] = {0};
        for(i = 1; i <= n; ++i)
        {
        	Max = A[i-1];
        	for(j = 1; j <= K && i-j>=0; ++j)
        	{
        		Max = max(Max, A[i-j]);
        		dp[i] = max(dp[i], dp[i-j]+j*Max);
        	}
        }
        return dp[n];
    }
};