class Solution {
public:
    int countVowelPermutation(int n) {
    	int mod = 1e9+7;
    	vector<vector<long long>> dp(n+1, vector<long long>(5, 0));
    	dp[1][0] = dp[1][1] = dp[1][2] = dp[1][3] = dp[1][4] = 1;
    	// a 0   e 1   i  2   o 3   u 4
    	//e,i,u --> a
    	//a, i --> e
    	//e o --> i
    	//i -- > o
    	//i o --> u
    	for(int k = 2; k <= n; ++k) 
    	{
    		dp[k][0] = (dp[k-1][1]+dp[k-1][2]+dp[k-1][4])%mod;
    		dp[k][1] = (dp[k-1][0]+dp[k-1][2])%mod;
    		dp[k][2] = (dp[k-1][1]+dp[k-1][3])%mod;
    		dp[k][3] = (dp[k-1][2])%mod;
    		dp[k][4] = (dp[k-1][2]+dp[k-1][3])%mod;
    	}
    	int ans = 0;
    	for(int i = 0; i < 5; i++)
    		ans = (ans+dp[n][i])%mod;
    	return ans;
    }
};