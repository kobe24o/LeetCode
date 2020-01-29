class Solution {
public:
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        int n = jobDifficulty.size(), i, j, k, MAX = 0;
        if(n < d)
        	return -1;
        vector<vector<int>> dp(d,vector<int>(n, INT_MAX));
        for(i = 0; i <= n-d; ++i)
        {
        	MAX = max(MAX, jobDifficulty[i]);
        	dp[0][i] = MAX;
        }
        for(i = 1; i < d; ++i)
        {
        	for(j = i; j <= n-d+i; ++j)
        	{
                MAX = 0;
                for(k = j; k <= n-d+i; ++k)
                {
                    MAX = max(MAX, jobDifficulty[k]);
        		    dp[i][k] = min(dp[i][k], MAX+dp[i-1][j-1]);
                }
        	}
        }
        return dp[d-1][n-1];
    }
};