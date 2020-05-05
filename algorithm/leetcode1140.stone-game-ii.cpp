class Solution {
public:
    int stoneGameII(vector<int>& piles) {
    	int i, j, k, n = piles.size(), l, r, M;
    	vector<int> presum(piles);
    	for(i = 1; i < n; ++i)
    		presum[i] = presum[i-1]+piles[i];
    	if(piles.size() <= 2)
    		return piles[n-1];
    	vector<<vector<int>>> dp(n,vector<int>(n+1,0));
    	//dp[i][j] 表示 剩余i堆石头，M为j时能得到的最多石头
    	for(i = 0; i < n; ++i)
    		for(j = 1; j <= n; ++j)
    			dp[i][]
    	for(i = 0; i < n; ++i)
    	{
    		for(j = 1; j <= i+1; ++j)
    		{
    			
    		}
    	}
    	return 
    }
};