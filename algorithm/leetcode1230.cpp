class Solution {
public:
    double probabilityOfHeads(vector<double>& prob, int target) {
    	int n = prob.size(), i, j, k;
    	vector<vector<double>> dp(n+1, vector<double>(target+1, 0.0));
    	dp[0][0] = 1.0;
    	for(i = 0; i < n; ++i)
    		for(j = 0; j <= min(i,target); ++j)
			{
				dp[i+1][j] += dp[i][j]*(1-prob[i]);
                if(j+1 <= target)
				    dp[i+1][j+1] += dp[i][j]*(prob[i]);
			}
		return dp[n][target];
    }
};