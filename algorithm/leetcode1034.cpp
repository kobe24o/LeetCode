class Solution {
public:
    vector<vector<int>> colorBorder(vector<vector<int>>& grid, int r0, int c0, int color) {
    	int m = grid.size(), n = grid[0].size(), i, j, k, x, y;
    	vector<vector<int>> dir = {{1,0},{0,1},{0,-1},{-1,0}};
    	int origin = grid[r0][c0];
    	vector<vector<bool>> vis(m, vector<bool>(n, false));
    	queue<pair<int,int>> q;
    	q.push(make_pair(r0, c0));
    	vis[r0][c0] = true;
    	while(!q.empty())
    	{
    		i = q.front().first;
    		j = q.front().second;
            q.pop();
    		for(k = 0; k < 4; ++k)
    		{
    			x = i + dir[k][0];
    			y = j + dir[k][1];
    			if(x >=0 && x<m && y>=0 && y<n)//在界内
    			{
                    if(vis[x][y]) continue;//访问过了，下一个
    				if(grid[x][y] != origin)//没有访问，颜色不同
    					grid[i][j] = color;// i, j 旁边的 x, y跟它不一样，边界
    				else//没有访问，颜色一样，正常入队
    				{
                        q.push({x,y});
                        vis[x][y] = true;
                    }
    			}
    			else//出界了
    				grid[i][j] = color;//i,j 是边界
    		}
    	}
    	return grid;
    }
};

class Solution {
    vector<vector<int>> dir = {{1,0},{0,1},{0,-1},{-1,0}};
    int m, n, origin, col;
public:
    vector<vector<int>> colorBorder(vector<vector<int>>& grid, int r0, int c0, int color) {
        m = grid.size(), n = grid[0].size();
        origin = grid[r0][c0], col = color;
        vector<vector<bool>> vis(m, vector<bool>(n, false));
        vis[r0][c0] = true;
        dfs(grid,r0,c0,vis);
        return grid;
    }
    void dfs(vector<vector<int>>& grid, int i, int j, vector<vector<bool>>& vis)
    {
        int x, y, k;
        for(k = 0; k < 4; ++k)
        {
            x = i + dir[k][0];
            y = j + dir[k][1];
            if(x >=0 && x<m && y>=0 && y<n)//在界内
            {
                if(vis[x][y]) continue;//访问过了，下一个
                if(grid[x][y] != origin)//没有访问，颜色不同
                    grid[i][j] = col;// i, j 旁边的 x, y跟它不一样，边界
                else//没有访问，颜色一样，正常入队
                {
                    vis[x][y] = true;
                    dfs(grid, x, y, vis);
                }
            }
            else//出界了
                grid[i][j] = col;//i,j 是边界
        }
    }
};