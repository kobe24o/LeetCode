class Solution {
public:
    int maxProfit(vector<int>& prices) {
    	if(prices.empty())
    		return 0;
    	int i, j, k, n = prices.size(), maxt = 2;
    	vector<vector<vector<int>>> dp(n,vector<vector<int>>(maxt+1,vector<int>(2,0)));
    	for(i = 0; i < n; ++i)
    	{
    		for(k = 1; k <= maxt; ++k)
    		{
    			if(i==0)
    			{
                    dp[i][k][0]=0;
                    dp[i][k][1]=-prices[0];
                    continue;
                }
    			dp[i][k][0] = max(dp[i-1][k][0], dp[i-1][k][1]+prices[i]);
    			dp[i][k][1] = max(dp[i-1][k][1], dp[i-1][k-1][0]-prices[i]);
    		}
    	}
    	return dp[n-1][2][0];
    }
};