class Solution {
	vector<vector<int>> path;
    vector<vector<int>> ans;
	int m, n;
	bool found = false;
	vector<vector<int>> dir = {{1,0},{0,1}};
public:
    vector<vector<int>> pathWithObstacles(vector<vector<int>>& grid) {
    	if(grid.empty() || grid[0].empty())
    		return {};
    	m = grid.size(), n = grid[0].size();
        if(grid[0][0]==1 || grid[m-1][n-1]==1)
    		return {};
    	vector<vector<bool>> visited(m, vector<bool>(n,false));
    	dfs(grid,0,0,visited);
    	return ans;
    }


    void dfs(vector<vector<int>>& grid, int i, int j, vector<vector<bool>> & visited)
    {
    	if(found)
    		return;
    	if(i == m-1 && j == n-1)
    	{
    		path.push_back({i,j});
            ans = path;
    		found = true;
    		return;
    	}
    	visited[i][j] = true;
    	path.push_back({i,j});
    	int x, y;
    	for(int k = 0; k < 2; ++k)
    	{
    		x = i + dir[k][0];
    		y = j + dir[k][1];
    		if(x>=0 && x<m && y>=0 && y<n && grid[x][y]==0 && !visited[x][y])
    			dfs(grid,x,y,visited);
    	}
    	// visited[i][j] = false;//不注释会超时
    	path.pop_back();
    }
};

class Solution {
public:
    vector<vector<int>> pathWithObstacles(vector<vector<int>>& grid) {
    	if(grid.empty() || grid[0].empty())
    		return {};
    	int m = grid.size(), n = grid[0].size(), i, j, k;
        if(grid[0][0]==1 || grid[m-1][n-1]==1)
    		return {};
    	vector<vector<bool>> dp(m,vector<bool>(n,false));//求每个位置是否可以到达
    	for(i = 0; i < m; ++i)
    	{
    		if(grid[i][0]==1)
    			break;
    		else
    			dp[i][0] = true;
    	}
    	for(j = 0; j < n; ++j)
    	{
    		if(grid[0][j]==1)
    			break;
    		else
    			dp[0][j] = true;
    	}
    	for(i = 1; i < m; i++)
    	{
    		for(j = 1; j < n; j++)
    		{
    			if(grid[i][j]==0)//不是障碍物
    				dp[i][j] = (dp[i-1][j] || dp[i][j-1]);
    		}
    	}
    	if(dp[m-1][n-1]==false)//到不了终点
    		return {};
    	vector<vector<int>> ans(m+n-1);
    	k = m+n-2, i = m-1, j = n-1;
    	while(i!=0 || j!=0)
    	{
    		ans[k--] = {i,j};
    		if(i-1>=0 && dp[i-1][j])
    			i--;
    		else if(j-1>=0 && dp[i][j-1])
    			j--;
    	}
        ans[0] = {0,0};
    	return ans;
    }
};