class Solution {
public:
    int countCornerRectangles(vector<vector<int>>& grid) {
    	int m = grid.size(), n = grid[0].size(), r, c1, c2, count = 0;
        vector<vector<int>> dp(n, vector<int>(n, 0));
        for(r = 0; r < m; ++r)
        {
        	for(c1 = 0; c1 < n; ++c1)
        	{
        		if(grid[r][c1])
        		{
        			for(c2 = c1+1; c2 < n; ++c2)
        			{
        				if(grid[r][c2])
        				{
        					count += dp[c1][c2];
        					dp[c1][c2]++;
        				}
        			}
        		}
        	}
        }
        return count;
    }
};