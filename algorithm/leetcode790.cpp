class Solution {
public:
    int numTilings(int N) {
    	if(N == 1) return 1;
    	vector<vector<long long>> dp(N+1, vector<long long>(4, 0));
    	dp[0][0] = 1;
    	int mod = 1e9+7;
    	for(int i = 1; i <= N; i++)
    	{
    		dp[i][0] = (dp[i-1][0]+dp[i-1][3])%mod;
    		dp[i][1] = (dp[i-1][0]+dp[i-1][2])%mod;
    		dp[i][2] = (dp[i-1][0]+dp[i-1][1])%mod;
    		dp[i][3] = (dp[i-1][0]+dp[i-1][1]+dp[i-1][2])%mod;
    	}
    	return dp[N][0];
    }
};