class Solution {
	vector<vector<int>> dir = { {1,0},{0,1},{0,-1},{-1,0}};
	int N;
public:
    int swimInWater(vector<vector<int>>& grid) {
        int l = grid[0][0], r = 2500, mid, ans;
        N = grid.size();
        while(l <= r)
        {
        	mid = (l + r) / 2;
        	vector<vector<bool>> vis(N, vector<bool>(N,false));
        	if(dfs(grid,0,0, mid, vis))
        	{
        		ans = mid;
        		r = mid-1;
        	}
        	else
        		l = mid+1;
        }
        return ans;
    }
    bool dfs(vector<vector<int>>& grid, int x, int y, int MAX, vector<vector<bool>>& vis)
    {
    	vis[x][y] = true;
    	int i, j, k;
    	if(x == N-1 && y == N-1)
    	{
    		return true;
    	}
    	for(k = 0; k < 4; k++)
    	{
    		i = x + dir[k][0];
    		j = y + dir[k][1];
    		if(i >=0 && i < N && j >=0 && j < N && !vis[i][j] && grid[i][j] <= MAX)
    		{
    			if(dfs(grid, i, j, MAX, vis))
    				return true;
    		}
    	}
    	return false;
    }
};