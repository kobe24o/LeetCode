class Solution {
public:
    int numWays(int n, int k) {
    	if(n==0 || k==0)
    		return 0;
    	vector<int> dp(n,0);
    	//dp[i]表示遍历完i栅栏的方案数
    	if(n>=1)
    		dp[0] = k;
    	if(n>=2)
    		dp[1] = k*k;
    	for(int i = 2; i < n; ++i)
    	{
    		dp[i] = dp[i-1]*(k-1)+dp[i-2]*(k-1);
    	}
    	return dp[n-1];
    }
};