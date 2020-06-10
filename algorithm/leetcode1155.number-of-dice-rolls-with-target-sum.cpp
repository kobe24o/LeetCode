class Solution {
public:
    int numRollsToTarget(int d, int f, int target) {
    	vector<vector<int>> dp(d+1,vector<int>(target+1, 0));
    	dp[0][0] = 1;
    	int i,j,k;
    	for(i = 1; i <= d; ++i)
    	{
    		for(j = 0; j < target; ++j)
    		{
    			if(dp[i-1][j] != 0)
    			{
    				for(k = 1; k <= f; ++k)
    				{
    					if(j+k <= target)
    						dp[i][j+k] = (dp[i][j+k]+dp[i-1][j])%1000000007;
    				}
    			}
    		}
    	}
    	return dp[d][target];
    }
};