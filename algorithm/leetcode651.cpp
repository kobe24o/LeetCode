class Solution {
public:
    int maxA(int N) {
    	vector<int> dp(N+1,0);
    	//dp[i] 表示，第 i 次按下键的最多A个数
    	for(int i = 1, j; i <= N; ++i)
    	{
    		dp[i] = max(dp[i], dp[i-1]+1);
    		for(j = 0; j <= i-2; ++j)
    			dp[i] = max(dp[i], dp[j]*(i-j-1));
    	}
    	return dp[N];
    }
};