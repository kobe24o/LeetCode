class Solution {
public:
    int findLength(vector<int>& A, vector<int>& B) {
    	int i, j, m = A.size(), n = B.size(), maxlen = 0;
    	vector<vector<int>> dp(m+1,vector<int>(n+1, 0));
    	for(i = 1; i <= m; ++i)
    	{
    		for(j = 1; j <= n; ++j)
    		{
    			if(A[i-1] == B[j-1])
    				dp[i][j] = dp[i-1][j-1]+1;
    			maxlen = max(maxlen, dp[i][j]);
    		}
    	}
    	return maxlen;
    }
};