class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& M) {
        vector<vector<int>> dir = {{1,0},{0,1},{0,-1},{-1,0},{1,1},{1,-1},{-1,1},{-1,-1}};
        int i, j, x, y, k, sum, count;
        int m = M.size(), n = M[0].size();
        vector<vector<int>> ans(M);
        for(i = 0; i < m; ++i)
        {
        	for(j = 0; j < n; ++j)
        	{	
        		sum = M[i][j];
        		count = 1;
        		for(k = 0; k < 8; ++k)
        		{
        			x = i+dir[k][0];
        			y = j+dir[k][1];
        			if(x>=0 && x<m && y>=0 && y<n)
        			{
        				sum += M[x][y];
        				count++;
        			}
        		}
        		ans[i][j] = sum/count;
        	}
        }
        return ans;
    }
};