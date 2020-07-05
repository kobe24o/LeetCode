class Solution {
public:
    int numSubmat(vector<vector<int>>& mat) {
    	int m = mat.size(), n = mat[0].size();
    	int i, j,k, width, count = 0;
    	vector<vector<int>> left1(m, vector<int>(n,0));
    	
    	for(i = 0; i < m; i++) 
    	{
    		count = 0;
    		for(j = 0; j < n; j++)
    		{
    			if(mat[i][j])
    				count++;
    			else
    				count = 0;
    			left1[i][j] = count;
    		}
    	}
    	count = 0;
    	for(i = 0; i < m; i++) 
    	{
    		for(j = 0; j < n; j++)
    		{
    			if(mat[i][j] == 0)
    				continue;
    			width = n;
    			for(k = i; k >= 0 && mat[k][j]; --k)
    			{
    				width = min(width, left1[k][j]);
    				count += width;
    			}
    		}
    	}
    	return count;
    }
};