class Solution {
public:
    int minScoreTriangulation(vector<int>& A) {
    	int n = A.size(), len, i, j, k;
    	vector<vector<int>> dp(n, vector<int>(n, 0));
    	for(len = 3; len <= n; ++len)
    	{
    		for(i = 0; i < n; ++i)
    		{
    			j = i+len-1;
    			if(j >= n) continue;
    			dp[i][j] = INT_MAX;
    			for(k = i+1; k < j; ++k)
    			{
    				dp[i][j] = min(dp[i][j], dp[i][k]+A[i]*A[k]*A[j]+dp[k][j]);
    			}
    		}
    	}
    	return dp[0][n-1];
    }
};