class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
    	int m = grid.size(), n = grid[0].size();
    	int i, j, x0, y0, x, y, k, count = 0, dis = 0, size;
    	vector<vector<bool>> visited(m, vector<bool>(n,false));
    	queue<vector<int>> q;
    	vector<vector<int>> dir = {{1,0},{0,1},{0,-1},{-1,0}};
    	for(i = 0; i < m; ++i)
    	{
    		for(j = 0; j < n; ++j)
    		{
    			if(grid[i][j])
    			{
    				q.push({i,j});
    				visited[i][j] = true;
    				count++;
    			}
    		}
    	}
    	if(count==0 || count==m*n)
    		return -1;
    	while(!q.empty())
    	{
    		size = q.size();
    		while(size--)
    		{
    			x0 = q.front()[0];
    			y0 = q.front()[1];
                q.pop();
    			for(k = 0; k < 4; ++k)
    			{
    				x = x0 + dir[k][0];
    				y = y0 + dir[k][1];
    				if(x>=0 && x<m && y>=0 && y<n && !visited[x][y])
    				{
    					q.push({x,y});
    					visited[x][y] = true;
    				}
    			}
    		}
    		dis++;
    	}
    	return dis-1;
    }
};