class Solution {
	vector<vector<int>> dir = {{1,0},{0,1},{0,-1},{-1,0}};
	int m,n;
public:
    int closedIsland(vector<vector<int>>& grid) {
    	//可以总结为，找的过程中，不能出界，出界的岛屿不算
        int i, j, island = 0;
        m = grid.size(), n = grid[0].size();
        bool out;
        for(i = 0; i < m; ++i)
        {
        	for(j = 0; j < n; ++j)
        	{
        		if(grid[i][j] == 0)//陆地
        		{
        			out = false;//出界了吗？
        			grid[i][j] = 1;//访问过了，无需回溯，直接改
        			dfs(grid,i,j,out);
        			if(!out)
        				island++;
        		}
        	}
        }
        return island;
    }

    void dfs(vector<vector<int>>& grid, int i, int j, bool& out)
    {
    	int x, y, k;
    	for(k = 0; k < 4; ++k)
    	{
    		x = i+dir[k][0];
    		y = j+dir[k][1];
    		if(x>=0 && x<m && y>=0 && y<n)
    		{	//在范围内，是陆地
    			if(grid[x][y] == 0)
    			{
    				grid[x][y] = 1;//访问过
    				dfs(grid,x,y,out);
    			}
    		}
    		else//不在范围内
    			out = true;
    	}
    }
};

class Solution {
	vector<vector<int>> dir = {{1,0},{0,1},{0,-1},{-1,0}};
	int m,n;
public:
    int closedIsland(vector<vector<int>>& grid) {
    	//可以总结为，找的过程中，不能出界，出界的岛屿不算
        int i, j, island = 0, x, y, k;
        m = grid.size(), n = grid[0].size();
        queue<pair<int,int> > q;
        pair<int,int> tp;
        bool out;
        for(i = 0; i < m; ++i)
        {
        	for(j = 0; j < n; ++j)
        	{
        		if(grid[i][j] == 0)//陆地
        		{
	        		out = false;
        			grid[i][j] = 1;//访问过了，无需回溯，直接改
        			q.push({i,j});
        			while(!q.empty())
        			{
        				tp = q.front();
        				q.pop();
        				for(k = 0; k < 4; ++k)
        				{
        					x = tp.first+ dir[k][0];
        					y = tp.second + dir[k][1];
        					if(x>=0 && x<m && y>=0 && y<n)
				    		{	//在范围内，是陆地
				    			if(grid[x][y] == 0)
				    			{
				    				grid[x][y] = 1;//访问过
				    				q.push({x,y});
				    			}
				    		}
				    		else//不在范围内
				    			out = true;
        				}
        			}
	        		if(!out)
    					island++;
        		}
        	}
        }
        return island;
    }
};