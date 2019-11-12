class Solution {
	int maxS = 0;
	int m, n;
	vector<vector<int>> dir = {{1,0},{0,1},{0,-1},{-1,0}};
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int curS = 0, i, j, i0, j0, k, x, y;
        m = grid.size(), n = grid[0].size();
        queue<pair<int,int>> q;
        for(i = 0; i < m; ++i)
        {
        	for(j = 0; j < n; ++j)
        	{
        		if(grid[i][j])// == 1
        		{
        			q.push({i,j});
        			curS = 1;//当前面积为1
        			grid[i][j] = 0;//访问过了
        			while(!q.empty())
        			{
        				i0 = q.front().first;
        				j0 = q.front().second;
        				q.pop();
        				for(k = 0; k < 4; ++k)
        				{
        					x = i0+dir[k][0];
        					y = j0+dir[k][1];
        					if(x>=0 && x<m && y>=0 && y<n && grid[x][y])
        					{
        						q.push({x,y});
        						grid[x][y] = 0;//访问过了
        						curS++;
        					}
        				}
        			}
        			if(curS > maxS)
        				maxS = curS;
        		}
        	}
        }
        return maxS;
    }
};

class Solution {
	int maxS = 0;
	int m, n;
	vector<vector<int>> dir = {{1,0},{0,1},{0,-1},{-1,0}};
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int curS = 0, i, j;
        m = grid.size(), n = grid[0].size();
        for(i = 0; i < m; ++i)
        {
        	for(j = 0; j < n; ++j)
        	{
        		if(grid[i][j])// == 1
        		{
        			curS = 1;//当前面积为1
        			grid[i][j] = 0;//访问过了
        			dfs(grid,i,j,curS);
        			if(curS > maxS)
        				maxS = curS;
        		}
        	}
        }
        return maxS;
    }

    void dfs(vector<vector<int>>& grid, int i, int j, int &curS)
    {
    	int x, y, k;
    	for(k = 0; k < 4; ++k)
    	{
    		x = i+dir[k][0];
    		y = j+dir[k][1];
    		if(x>=0 && x<m && y>=0 && y<n && grid[x][y])
    		{
    			grid[x][y] = 0;//访问过了
    			curS++;
    			dfs(grid,x,y,curS);
    		}
    	}
    }
};