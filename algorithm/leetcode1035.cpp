class Solution {
public:
    int maxUncrossedLines(vector<int>& A, vector<int>& B) {
    	int n1 = A.size(), n2 = B.size(), i, j;
    	vector<vector<int>> dp(n1+1,vector<int>(n2+1, 0));
    	for(i = 1; i <= n1; i++)
    	{
    		for(j = 1; j <= n2; j++)
    		{
    			if(A[i-1] == B[j-1])
    				dp[i][j] = dp[i-1][j-1]+1;
    			else
    				dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
    		}
    	}
    	return dp[n1][n2];
    }
};