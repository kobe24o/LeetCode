class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
    	if(grid.empty())
    		return 0;
        int sum1 = 0, sum2 = 0, i, j, maxh;
        int v[grid.size()], h[grid[0].size()];
        for(i = 0; i < grid.size(); ++i)
        {
        	maxh = -1;
        	for(j = 0; j < grid.size(); ++j)
        	{
        		sum1 += grid[i][j];
        		if(grid[i][j] > maxh)
        			maxh = grid[i][j];
        	}
        	v[i] = maxh;
        }
        for(j = 0; j < grid.size(); ++j)
        {
        	maxh = -1;
        	for(i = 0; i < grid.size(); ++i)
        	{
        		if(grid[i][j] > maxh)
        			maxh = grid[i][j];
        	}
        	h[j] = maxh;
        }
        for(i = 0; i < grid.size(); ++i)
        {
        	for(j = 0; j < grid.size(); ++j)
        	{
        		grid[i][j] = min(v[i],h[j]);
        		sum2 += grid[i][j];
        	}
        }
        return sum2-sum1;
    }
};