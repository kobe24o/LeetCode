class Solution {
public:
    int findDerangement(int n) {
    	if(n==1) return 0;
    	vector<long long > dp(n+1, 0);
    	dp[0] = 1;
    	dp[1] = 0;
    	for(int i = 2; i <= n; ++i)
    		dp[i] = ((i-1)*(dp[i-1]+dp[i-2]))%1000000007;
    	return dp[n];
    }
};