class Solution {
	int m,n;
	int maxMoney = 0;
	vector<vector<int>> dir = {{1,0},{-1,0},{0,1},{0,-1}};
public:
    int getMaximumGold(vector<vector<int>>& grid) {
        m = grid.size(), n = grid[0].size();
        int i, j, origin;
        for(i = 0; i < m; ++i)
        {
        	for(j = 0; j < n; ++j)
        	{
        		if(grid[i][j] != 0)
        		{
        			origin = grid[i][j];
        			grid[i][j] = 0;//挖掉了
        			dfs(grid,i,j,origin);
        			grid[i][j] = origin;//恢复现场
        		}
        	}
        }
        return maxMoney;
    }

    void dfs(vector<vector<int>>& grid, int i, int j, int curMoney)
    {
    	if(curMoney > maxMoney)
    		maxMoney = curMoney;
    	int x, y, origin;
    	for(int k = 0; k < 4; ++k)
    	{
    		x = i+dir[k][0];
    		y = j+dir[k][1];
    		if(x>=0 && x<m && y>=0 && y<n && grid[x][y] != 0)
    		{
    			origin = grid[x][y];
    			grid[x][y] = 0;//挖掉了
    			dfs(grid,x,y,curMoney+origin);
    			grid[x][y] = origin;//恢复现场
    		}
    	}
    }
};