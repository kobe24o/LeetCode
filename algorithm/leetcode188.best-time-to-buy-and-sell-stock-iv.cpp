class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        if(prices.empty())
            return 0;
        int i, deal, n = prices.size();
        if(k > n/2)//股票第二题
        {
            int maxprofit = 0;
            for(int i = 1; i < prices.size(); i++) 
            {
                if(prices[i] > prices[i-1])
                    maxprofit += prices[i] - prices[i-1];
            }
            return maxprofit;
        }
        int dp[n][k+1][2];
        memset(dp,0,sizeof(dp));
        for(i = 0; i < n; ++i)
        {
            for(deal = 1; deal <= k; ++deal)
            {
                if(i == 0)
                {
                    dp[i][deal][0] = 0;
                    dp[i][deal][1] = -prices[0];
                    continue;
                }
                dp[i][deal][0] = max(dp[i-1][deal][0], dp[i-1][deal][1]+prices[i]);
                dp[i][deal][1] = max(dp[i-1][deal][1], dp[i-1][deal-1][0]-prices[i]);
            }
        }
        return dp[n-1][k][0];
    }
};