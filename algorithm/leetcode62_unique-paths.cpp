class Solution {
public:
    int uniquePaths(int m, int n) {
        int dp[n][m], i, j;
        for(i = 0; i < n; ++i)
        	dp[i][0] = 1;
        for(j = 1; j < m; ++j)
        	dp[0][j] = 1;
        for(i = 1; i < n; ++i)
        	for(j = 1; j < m; ++j)
        		dp[i][j] = dp[i-1][j]+dp[i][j-1];
    	return dp[n-1][m-1];
    }
};