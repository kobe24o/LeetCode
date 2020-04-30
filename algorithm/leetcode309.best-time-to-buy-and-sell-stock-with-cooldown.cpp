class Solution {
public:
    int maxProfit(vector<int>& prices) {
    	if(prices.size() <= 1)
    		return 0;
    	int i, n = prices.size();
        vector<vector<int>> dp(n,vector<int>(2,0));
        dp[0][0] = 0;
        dp[0][1] = -prices[0];
        dp[1][0] = max(dp[0][0], dp[0][1]+prices[1]);
        dp[1][1] = max(dp[0][1], dp[0][0]-prices[i]);
        for(i = 2; i < n; ++i)
        {
            dp[i][0] = max(dp[i-1][0], dp[i-1][1]+prices[i]);
            			// 休息，       前一天有股票，卖出
            dp[i][1] = max(dp[i-1][1], dp[i-2][0]-prices[i]);
                        // 休息，       前2天没股票，买入，要隔一天
        }
        return dp[n-1][0];
    }
};