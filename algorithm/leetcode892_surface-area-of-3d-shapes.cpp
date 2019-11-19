class Solution {
public:
    int surfaceArea(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size(), i, j, k, s = 0, x, y;
        vector<vector<int>> dir = {{1,0},{0,1},{0,-1},{-1,0}};
        for(i = 0; i < m; ++i)
        	for(j = 0; j < n; ++j)
        	{
        		if(grid[i][j] == 0)
        			continue;
        		s += 2+(grid[i][j]<<2);//上下表面2+4*h
        		for(k = 0; k < 4; ++k)
        		{
        			x = i+dir[k][0];
        			y = j+dir[k][1];
        			if(x>=0 && x<m && y>=0 && y<n)
        				s -= min(grid[i][j],grid[x][y]);
        		}
        	}
    	return s;
    }
};

class Solution {
public:
    int surfaceArea(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size(), i, j, k, s = 0, x, y;
        vector<vector<int>> dir = {{1,0},{0,1}};
        for(i = 0; i < m; ++i)
        	for(j = 0; j < n; ++j)
        	{
        		if(grid[i][j] == 0)
        			continue;
        		s += 2+(grid[i][j]<<2);//上下表面2+4*h
        		for(k = 0; k < 2; ++k)
        		{
        			x = i+dir[k][0];
        			y = j+dir[k][1];
        			if(x>=0 && x<m && y>=0 && y<n)
        				s -= 2*min(grid[i][j],grid[x][y]);
        		}
        	}
    	return s;
    }
};