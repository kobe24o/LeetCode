class Solution {
public:
    int maxValue(vector<vector<int>>& grid) {
    	if(grid.empty() || grid[0].empty())
    		return 0;
    	int m = grid.size(), n = grid[0].size(), i, j;
    	vector<vector<int>> dp(m, vector<int>(n,0));
    	dp[0][0] = grid[0][0];
    	for(j = 1; j < n; j++)
    		dp[0][j] = dp[0][j-1] + grid[0][j];
    	for(i = 1; i < m; ++i)
    		dp[i][0] = dp[i-1][0] + grid[i][0];
    	for(i = 1; i < m; ++i)
    		for(j = 1; j < n; j++)
    			dp[i][j] = grid[i][j] + max(dp[i][j-1], dp[i-1][j]);
		return dp[m-1][n-1];
    }
};