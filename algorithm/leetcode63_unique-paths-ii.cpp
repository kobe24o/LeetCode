class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
    	if(obstacleGrid.empty()||obstacleGrid[0][0] == 1)
    		return 0;
        int m = obstacleGrid.size(), n = obstacleGrid[0].size();
        int i, j;
        long dp[m][n];
        memset(dp,0,m*n*sizeof(long long));
        for(i = 0; i < m; i++)
        	if(obstacleGrid[i][0] == 0)
        		dp[i][0] = 1;
        	else
        		break;//遇到障碍走不通
        for(i = 1; i < n; i++)
        	if(obstacleGrid[0][i] == 0)
        		dp[0][i] = 1;
        	else
        		break;
        for(i = 1; i < m; i++)
        	for(j = 1; j < n; j++)
        		if(obstacleGrid[i][j] == 0)//无障碍
        			dp[i][j] = dp[i][j-1]+dp[i-1][j];
    	return dp[m-1][n-1];
    }
};