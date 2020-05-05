class Solution {
public:
    int stoneGameII(vector<int>& piles) {
    	int i, j, k, n = piles.size(), l, r, M;
    	vector<int> presum(piles);
    	for(i = 1; i < n; ++i)
    		presum[i] = presum[i-1]+piles[i];
    	if(piles.size() <= 2)
    		return piles[n-1];
    	vector<<vector<int>>> dp(n+1,vector<int>(n+1,0));
    	//dp[i][j] 表示 剩余i堆石头，M为j时能得到的最多石头
    	for(i = 1; i <= n; ++i)
    	{
    		for(j = i; j <= n; ++j)
    		{
    			dp[i][j] = presum[n-1]-presum[n-j-1];//可以全部拿走
    		}
    	}
    	for(i = 1; i <= n; ++i)
    	{
    		for(j = 1; j <= i; ++j)
    		{
    			for(k = 1; k <= min(2*j, i); ++k)
    			{
    				dp[i][j] = max(dp[i][j], presum[n-1]-presum[n-k-1])
    			}
    		}
    	}
    	return 
    }
};