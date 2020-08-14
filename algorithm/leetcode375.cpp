class Solution {
public:
    int getMoneyAmount(int n) {
    	vector<vector<int>> dp(n+1, vector<int>(n+1, INT_MAX));
    	// dp[i][j] 表示答案在 区间 [i,j] 内所需的最小花费
    	for(int i = 1; i <= n; i++) 
    		dp[i][i] = 0;
    	for(int len = 1; len <= n; len++) 
    	{
    		for(int i = 1; i <= n-len; i++)
    		{
    			int j = i+len;
    			dp[i][j] = min(i + dp[i+1][j], j + dp[i][j-1]);
    			for(int k = i+1; k < j; k++)
    			{
    				dp[i][j] = min(dp[i][j], max(dp[i][k-1], dp[k+1][j])+k);
    			}
    		}
    	}
    	return dp[1][n];
    }
};