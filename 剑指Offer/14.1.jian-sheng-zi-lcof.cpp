class Solution {
public:
    int cuttingRope(int n) {
        int dp[n+1] = {0};
        dp[2] = 1;
        int i, j;
        for(i = 3; i <= n; ++i)
        {	
        	for(j = 1; j < i; ++j)
        		dp[i] = max(dp[i], max(j,dp[j])*max(i-j, dp[i-j]));
        }
        return dp[n];
    }
};