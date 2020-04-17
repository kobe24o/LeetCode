class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
    	int m = matrix.size(), n = matrix[0].size(), i, j, count = 0;
    	vector<vector<int>> dp(m,vector<int>(n,0));
    	//dp[i][j] 表示 以i,j为右下角的最大正方形边长
    	for(i = 0; i < m; ++i)
    	{
    		for(j = 0; j < n; ++j)
    		{
    			if(i==0 || j==0)
    				dp[i][j] = matrix[i][j];//最多边长1
    			else if(matrix[i][j]==1)
    				dp[i][j] = 1+min(dp[i-1][j],min(dp[i][j-1],dp[i-1][j-1]));
    			count += dp[i][j];
    		}
    	}
    	return count;
    }
};