class Solution {
	int x, y, sum;
	int nb[10];
public:
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size(), i, j, count = 0;
        for(i = 0; i <= m-3; ++i)
        	for(j = 0; j <= n-3; ++j)
        	{
        		if(grid[i+1][j+1] != 5)
        			continue;
        		if(isMagic(i,j,grid))
        			count++;
        	}
    	return count;
    }

    bool isMagic(int &i, int &j, vector<vector<int>>& grid)
    {
    	memset(nb,0,sizeof nb);
    	for(x=i; x<i+3; ++x)
    	{
    		sum = 0;
    		for(y=j; y<j+3; ++y)
    		{
    			sum += grid[x][y];
    			if(grid[x][y]>=1 && grid[x][y]<=9 && nb[grid[x][y]]==0)
    				nb[grid[x][y]] = 1;
    		}
    		if(sum != 15)
				return false;
    	}
    	sum = 0;
    	for(x = 1; x <= 9; ++x)
    		sum += nb[x];
    	if(sum != 9)
    		return false;
    	for(y=j; y<j+3; ++y)
    	{
    		sum = 0;
    		for(x=i; x<i+3; ++x)
    			sum += grid[x][y];
    		if(sum != 15)
				return false;
    	}
    	sum = grid[i][j]+grid[i+1][j+1]+grid[i+2][j+2];
    	if(sum != 15)
			return false;
		return grid[i+2][j]+grid[i+1][j+1]+grid[i][j+2] == 15;
    }
};