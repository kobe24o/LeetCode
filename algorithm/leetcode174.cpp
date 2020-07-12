class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& grid) {
    	int m = grid.size(), n = grid[0].size(), i, j, minlife;
    	vector<vector<int>> dp(m+1,vector<int>(n+1, INT_MAX));
    	dp[m][n-1] = dp[m-1][n] = 1;//处理边界更方便
    	for(i = m-1; i >= 0; --i)
    	{
    		for(j = n-1; j >= 0; --j)
    		{
    			minlife = min(dp[i+1][j], dp[i][j+1]);//最少需要的生命值
    			dp[i][j] = max(minlife-grid[i][j], 1);
    			//              
    		}
    	}
    	return dp[0][0];
    }
};