class Solution {
public:
    int stoneGameII(vector<int>& piles) {
        int i, m, x, n = piles.size();
        vector<int> presum(piles.size()+1, 0);
        for(i = 1; i <= n; ++i)
            presum[i] = presum[i-1]+piles[i-1];
        if(piles.size() <= 2)
            return piles[n-1];
        vector<vector<int>> dp(n+1,vector<int>(n+1,0));
        //dp[i][m] 表示 剩余i堆石头，M为m时能得到的最多石头
        for(i = 0; i <= n; ++i)
        {
            for(m = i; m <= n; ++m)
            {
                dp[i][m] = presum[n]-presum[n-i];//可以全部拿走
            }
        }
        for(i = 1; i <= n; ++i)
        {
            for(m = 1; m <= n; ++m)
            {
                for(x = 1; x <= min(2*m, i); ++x)
                {
                    dp[i][m] = max(dp[i][m], presum[n]-presum[n-i]-dp[i-x][min(n,max(x, m))]);
                }
            }
        }
        return dp[n][1];
    }
};