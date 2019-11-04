class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int i, j, k, len, x, y, goodfruits = 0;
        int m = grid.size(), n = grid[0].size(), minutes = -1;
        queue<pair<int,int>> q;
        for(i = 0; i < m; ++i)
        	for(j = 0; j <n; ++j)
        		if(grid[i][j] == 2)
        		{
        			q.push({i,j});
        			grid[i][j] = -1;
        		}
        		else if(grid[i][j] == 1)
        			goodfruits++;
		if(goodfruits == 0)
			return 0;
		vector<pair<int,int>> dir = {{1,0},{-1,0},{0,1},{0,-1}};
		while(!q.empty())
		{
			len = q.size();
			while(len--)
			{
				for(k = 0; k < 4; ++k)
				{
					x = q.front().first+dir[k].first;
					y = q.front().second+dir[k].second;
					if(x>=0 && x<m && y>=0 && y<n && grid[x][y]!= -1 && grid[x][y]==1)
					{
						q.push({x,y});
						grid[x][y] = -1;
						goodfruits--;
					}
				}
				q.pop();
			}
            ++minutes;
		}
		if(goodfruits)
			return -1;
		return minutes;
    }
};