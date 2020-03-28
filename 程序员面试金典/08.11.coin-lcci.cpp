class Solution {
public:
    int waysToChange(int n) {
    	int coin[4] = {1,5,10,25};
    	vector<int> dp(n+1,0);
    	dp[0] = 1;
    	int i, j, money;
    	for(i = 0; i < 4; ++i)
    	{
            for(j = 0; j <= n; ++j)
            {
                if(dp[j]!= 0 && j+coin[i] <= n)
                    dp[j+coin[i]] = (dp[j+coin[i]] + dp[j])%1000000007;
            }
    	}
    	return dp[n]%1000000007;
    }
};
