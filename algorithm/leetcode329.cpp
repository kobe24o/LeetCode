class Solution {
	int m, n;
	int longest = 1;
	vector<vector<int>> dir = {{-1,0},{1,0},{0,1},{0,-1}};
public:
    int longestIncreasingPath(vector<vector<int>>& mat) {
    	if(mat.empty() || mat[0].empty())
    		return 0;
    	m = mat.size(), n = mat[0].size();
    	vector<vector<int>> s(m, vector<int>(n,0));
    	for(int i = 0, j; i < m; ++i)
    		for(j = 0; j < n; ++j)
    		{
    			if(s[i][j] != 0)
    				continue;
    			longest = max(longest, dfs(i,j,mat,s));
    		}
    	return longest;
    }
    int dfs(int i, int j, vector<vector<int>>& mat, vector<vector<int>>& s)
    {
        if(s[i][j] != 0)
            return s[i][j];
    	int x, y, k, longestpathofnext = 0;
    	for(k = 0; k < 4; ++k)
    	{
    		x = i + dir[k][0];
    		y = j + dir[k][1];
    		if(x>=0 && x<m && y>=0 && y<n && mat[i][j] > mat[x][y])
    		{
    			longestpathofnext = max(longestpathofnext, dfs(x,y,mat,s));
    		}
    	}
    	return s[i][j] = 1+longestpathofnext;
    }
};