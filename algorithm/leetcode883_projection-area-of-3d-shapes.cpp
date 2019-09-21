class Solution {
public:
    int projectionArea(vector<vector<int>>& grid) {
        int bot = 0, left = 0, front = 0, i, j;
        for(i = 0; i < grid.size(); ++i)
        {
        	for(j = 0; j < grid[0].size(); ++j)
        	{
        		if(grid[i][j] != 0)
        			++bot;
        	}
        }
        int max;
        for(i = 0; i < grid.size(); ++i)
        {
        	max = 0;
        	for(j = 0; j < grid[0].size(); ++j)
        	{
        		if(grid[i][j] > max)
        			max = grid[i][j];
        	}
        	left += max;
        }
        for(j = 0; j < grid[0].size(); ++j)
        {
        	max = 0;
        	for(i = 0; i < grid.size(); ++i)
        	{
        		if(grid[i][j] > max)
        			max = grid[i][j];
        	}
        	front += max;
        }
        return front+left+bot;
    }
};