class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        if(grid.empty())
        	return 0;
        int m = grid.size(), n = grid[0].size();
        int dp[m][n], i, j;
        dp[0] = grid[0][0];
        for(i = 1; i < m; i++)
        	dp
    }
};