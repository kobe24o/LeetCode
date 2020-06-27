class Solution {
public:
    int shortestPath(vector<vector<int>>& grid, int k) {
    	vector<vector<int>> dir = {{1,0},{0,1},{0,-1},{-1,0}};
        int m = grid.size(), n = grid[0].size(), i, j, ni, nj, s = 0, d;
        vector<vector<vector<int>>> dp(m,vector<vector<int>>(n, vector<int>(k+1, INT_MAX)));
        // dp[i][j][s] 表示到（i,j）位置,消除了s个障碍物的最短步数
        dp[0][0][0] = 0;
        vector<vector<bool>> vis(m, vector<bool>(n,false));
        queue<vector<int>> q;
        q.push({0,0});
        vis[0][0] = true;
        while (!q.empty()) 
        {
        	int size = q.size();
        	while(size--)
        	{
        		i = q.front()[0];
	        	j = q.front()[1];
                q.pop();
	        	dp[i][j][0] = s;
	        	for(d = 0; d < 4; ++d)
	        	{
	        		ni = i+dir[d][0];
        			nj = j+dir[d][1];
        			if(ni<0 || ni >= m || nj<0 || nj >= n || vis[ni][nj] || grid[ni][nj])
        				continue;//出界了，访问过，是障碍物
        			q.push({ni,nj});
        			vis[ni][nj] = true;
	        	}
        	}
        	s++;
        }
        for(s = 0; s <= k; s++)
        {
        	for(i = 0; i < m; i++) 
	        {
	        	for(j = 0; j < n; j++)
	        	{
                    if(dp[i][j][s] == INT_MAX)
                        continue;
	        		for(d= 0; d < 4; ++d)
	        		{
	        			ni = i+dir[d][0];
	        			nj = j+dir[d][1];
	        			if(ni<0 || ni >= m || nj<0 || nj >= n)
	        				continue;
	        			if(grid[ni][nj] && s+1 <= k)//障碍物, 还可以搬走
		        			dp[ni][nj][s+1] = min(dp[ni][nj][s+1], dp[i][j][s]+1);
		        		else if(!grid[ni][nj])//不是障碍物
		        			dp[ni][nj][s] = min(dp[ni][nj][s], dp[i][j][s]+1);
	        		}
	        		
	        	}
	        }
        }
        int minstep = INT_MAX;
        for(s = 0; s <= k; ++s)
        	minstep = min(minstep, dp[m-1][n-1][s]);
        return minstep==INT_MAX ? -1 : minstep;
    }
};


class Solution {
public:
    int shortestPath(vector<vector<int>>& grid, int k) {
    	vector<vector<int>> dir = {{1,0},{0,1},{0,-1},{-1,0}};
        int m = grid.size(), n = grid[0].size(), i, j, ni, nj, step = 0, curs, d;
        vector<vector<vector<bool>>> vis(m,vector<vector<bool>>(n, vector<bool>(k+1, false)));
        queue<vector<int>> q;
        q.push({0,0,0});// i, j, s障碍物搬了几次
        vis[0][0][0] = true;
        while (!q.empty()) 
        {
        	int size = q.size();
        	while(size--)
        	{
        		i = q.front()[0];
	        	j = q.front()[1];
                curs = q.front()[2];
                if(i==m-1 && j==n-1)
                    return step;
                q.pop();
                for(d = 0; d < 4; ++d)
                {
                    ni = i+dir[d][0];
                    nj = j+dir[d][1];
                    if(ni<0 || ni >= m || nj<0 || nj >= n)
                        continue;//出界了
                    if(grid[ni][nj] && curs+1 <= k && !vis[ni][nj][curs+1])//是障碍物, 还能搬走
                    {
                        vis[ni][nj][curs+1] = true;
                        q.push({ni,nj,curs+1});
                    }
                    else if(!grid[ni][nj] && !vis[ni][nj][curs])//不是障碍物
                    {
                        vis[ni][nj][curs] = true;
                        q.push({ni,nj,curs});
                    }
                }
        	}
        	step++;
        }
        return -1;
    }
};