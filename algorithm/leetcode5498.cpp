class Solution {
public:
    int stoneGameV(vector<int>& stoneValue) {
    	int n = stoneValue.size(), i, l, r, mid, suml, sumr;
    	int dp[501][501];
        memset(dp,0,sizeof dp);
    	int sum[501] = {0};
        sum[0] = stoneValue[0];
    	for(i = 1; i < n; i++) 
    		sum[i] = sum[i-1] + stoneValue[i];
    	for(int len = 1; len < n; len++)
    	{
    		for(l = 0; l < n; l++)
    		{
    			r = l+len;
    			if(r >= n)
    				continue;
    			for(mid = l; mid < r; mid++)
    			{
    				suml = sum[mid]-(l==0 ? 0 : sum[l-1]);
    				sumr = sum[r]-sum[mid];
                    if(suml >= sumr)
    				    dp[l][r] = max(dp[l][r], dp[mid+1][r]+sumr);
                    if(suml <= sumr)
                        dp[l][r] = max(dp[l][r], dp[l][mid]+suml);
    			}
    		}
    	}
    	return dp[0][n-1];
    }
};