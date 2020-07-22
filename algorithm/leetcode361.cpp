class Solution {
public:
    int maxKilledEnemies(vector<vector<char>>& grid) {
    	if(grid.empty() || grid[0].empty())
    		return 0;
    	int m = grid.size(), n = grid[0].size(), i, j, pre = 0;
    	vector<vector<int>> ans(m, vector<int>(n,0));
    	//分四个方向求前缀和
    	for(i = 0; i < m; ++i)
    		for(j = 0, pre=0; j < n; ++j)
    		{
    			if(grid[i][j] =='W')
    				pre = 0;
    			else if(grid[i][j] =='E')
    				pre++;
    			else
    				ans[i][j] += pre;
    		}
    	for(i = 0; i < m; ++i)
    		for(j = n-1, pre=0; j >= 0; --j)
    		{
    			if(grid[i][j] =='W')
    				pre = 0;
    			else if(grid[i][j] =='E')
    				pre++;
    			else
    				ans[i][j] += pre;
    		}
    	for(j = 0; j < n; ++j)
    		for(i = 0, pre=0; i < m; ++i)
    		{
    			if(grid[i][j] =='W')
    				pre = 0;
    			else if(grid[i][j] =='E')
    				pre++;
    			else
    				ans[i][j] += pre;
    		}
    	for(j = 0; j < n; ++j)
    		for(i = m-1, pre=0; i >= 0; --i)
    		{
    			if(grid[i][j] =='W')
    				pre = 0;
    			else if(grid[i][j] =='E')
    				pre++;
    			else
    				ans[i][j] += pre;
    		}
    	int maxcount = 0;
    	for(i = 0; i < m; ++i)
    		for(j = 0; j < n; ++j)
    			maxcount = max(maxcount, ans[i][j]);
		return maxcount;
    }
};