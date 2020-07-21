class Solution {
public:
    int minTotalDistance(vector<vector<int>>& grid) {
    	int m = grid.size(), n = grid[0].size(), i, j, dis = 0;
    	vector<int> x, y;
    	for(i = 0; i < m; ++i)
    		for(j = 0; j < n; ++j)
    			if(grid[i][j])
    				x.push_back(i);
		for(j = 0; j < n; ++j)
			for( i = 0; i < m; ++i)
				if(grid[i][j])
					y.push_back(j);
		i = 0, j = x.size()-1;
		while(i < j)
			dis += x[j--]-x[i++];
		i = 0, j = y.size()-1;
		while(i < j)
			dis += y[j--]-y[i++];
		return dis;
    }
};