class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        vector<vector<int>> ans(grid);
        int n = grid.size(), m = grid[0].size();
        int i, j, x, y;
        for(i = 0; i < n; ++i)
        	for(j = 0; j < m; ++j)
        	{
        		x = (m*i+j+k)/m%n;
        		y = (m*i+j+k)%m;
        		ans[x][y] = grid[i][j];
        	}
    	return ans;
    }
};