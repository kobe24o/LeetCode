class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int i, j, count = 0;
        for(i = 0; i < grid.size(); ++i)
        {
        	for(j = 0; j < grid[i].size(); ++j)
        	{
        		if(grid[i][j] == 1)
        		{
        			count += 4;
	        		if(i > 0 && grid[i-1][j] == 1)
	        			count -= 1;
	        		if(i < grid.size()-1 && grid[i+1][j] == 1)
	        			count -= 1;
	        		if(j > 0 && grid[i][j-1] == 1)
	        			count -= 1;
	        		if(i < grid[i].size()-1 && grid[i][j+1] == 1)
	        			count -= 1;
	        	}
        	}
        }
        return count;
    }
};

class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
       int sum=0;
       for(int i=0;i<grid.size();i++)
       {
           for(int j=0;j<grid[0].size();j++)
           {
               if(grid[i][j]==1)
               {
                   sum+=4;
               if(i>0&&grid[i-1][j]==1) sum-=1;
               if(i<grid.size()-1&&grid[i+1][j]==1)sum-=1;
               if(j>0&&grid[i][j-1]==1)sum-=1;
               if(j<grid[0].size()-1&&grid[i][j+1]==1)sum-=1;
               }
           }
       }
       return sum;
    }
};