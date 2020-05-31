class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
    	int i, j1, j2, nj1, nj2,k1,k2, m = grid.size(), n = grid[0].size();
    	vector<vector<vector<int>>> dp(m,vector<vector<int>>(n, vector<int>(n,-1)));
    	//dp[i][j1][j2],表示第i层，两机器人位置为 j1, j2 的最大值
    	dp[0][0][n-1] = grid[0][0]+grid[0][n-1];
    	vector<int> dir = {-1,0,1};
    	int maxPick = 0;
    	for(i = 1; i < m; ++i)
    	{
    		for(j1 = 0; j1 < n; ++j1)
    		{
    			for(j2 = 0; j2 < n; ++j2)
    			{
    				if(dp[i-1][j1][j2] != -1)
	    			{
	    				for(k1 = 0; k1 < 3; ++k1)
	    				{
	    					nj1 = j1 + dir[k1];
	    					for(k2 = 0; k2 < 3; ++k2)
	    					{
	    						nj2 = j2 + dir[k2];
	    						if(nj1 >= 0 && nj1 < n && nj2 >= 0 && nj2 < n)
	    						{
	    							if(nj1 == nj2)
	    								dp[i][nj1][nj2] = max(dp[i][nj1][nj2], dp[i-1][j1][j2]+grid[i][nj1]);
	    							else
	    								dp[i][nj1][nj2] = max(dp[i][nj1][nj2], dp[i-1][j1][j2]+grid[i][nj1]+grid[i][nj2]);	
	    						}
	    					}
	    				}
	    			}
    			}    			
    		}
    	}
        for(j1 = 0; j1 < n; ++j1)
            for(j2 = 0; j2 < n; ++j2)
                maxPick = max(maxPick, dp[m-1][j1][j2]);
    	return maxPick;
    }
};