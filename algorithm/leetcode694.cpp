class Solution {
public:
    int numDistinctIslands(vector<vector<int>>& grid) {
        if(grid.empty() || grid[0].empty()) return 0;
        int m = grid.size(), n = grid[0].size(), i, j, k, x, y, x0, y0, nx, ny;
        vector<vector<int>> dir = {{1,0},{0,1},{0,-1},{-1,0}};
        set<vector<vector<int>>> s;
        for(i = 0; i < m; ++i)
        {
        	for(j = 0; j < n; ++j)
        	{
        		if(grid[i][j] == 0)
        			continue;
        		x0 = i, y0 = j;
        		queue<vector<int>> q;
        		vector<vector<int>> path;
        		q.push({x0, y0});
        		grid[x0][y0] = 0;//访问过
        		while(!q.empty())
        		{
        			x = q.front()[0];
        			y = q.front()[1];
        			path.push_back({x-x0, y-y0});//路径记录相对坐标
        			q.pop();
        			for(k = 0; k < 4; ++k)
        			{
        				nx = x + dir[k][0];
        				ny = y + dir[k][1];
        				if(nx>=0 && nx<m && ny>=0 && ny<n && grid[nx][ny])
        				{
        					q.push({nx, ny});
        					grid[nx][ny] = 0;//访问过
        				}
        			}
        		}
        		s.insert(path);
        	}
        }
        return s.size();
    }
};

class Solution {
    vector<vector<int>> dir = {{1,0},{0,1},{0,-1},{-1,0}};
    int m, n;
    set<vector<vector<int>>> s;
public:
    int numDistinctIslands(vector<vector<int>>& grid) {
        if(grid.empty() || grid[0].empty()) return 0;
        m = grid.size(), n = grid[0].size();
        for(int i = 0, j; i < m; ++i)
        {
            for(j = 0; j < n; ++j)
            {
                if(grid[i][j] == 0)
                    continue;
                vector<vector<int>> path;
                grid[i][j] = 0;//访问过
                DFS(grid,i,j,i,j,path);
                s.insert(path);
            }
        }
        return s.size();
    }

    void DFS(vector<vector<int>>& grid, int x0, int y0, int x, int y, vector<vector<int>>& path)
    {
        path.push_back({x-x0, y-y0});//路径记录相对坐标
        int k, nx, ny;
        for(k = 0; k < 4; ++k)
        {
            nx = x + dir[k][0];
            ny = y + dir[k][1];
            if(nx>=0 && nx<m && ny>=0 && ny<n && grid[nx][ny])
            {
                grid[nx][ny] = 0;//访问过
                DFS(grid, x0, y0, nx, ny, path);
            }
        }
    }
};