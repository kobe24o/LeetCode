class Solution {
public:
    double new21Game(int N, int K, int W) {
    	vector<double> dp(N+1, 0.0);
    	dp[0] = 1;
    	double prob = 1.0;
    	int i;
    	for(i = 1; i<K && i<=W; ++i)
    	{
    		dp[i] = prob/W;
    		prob += dp[i];
    	}
    	for( ; i < K; ++i)
    	{
    		dp[i] = (prob-dp[i-W-1])/W;
    		prob += dp[i] - dp[i-W-1];
    	}
    	for( ; i <= N; ++i)
    	{
    		dp[i] = (prob-dp[i-W-1])/W;
    	}
    	for(i = K, prob = 0.0; i <= N; ++i)
    		prob += dp[i];
    	return prob;
    }
};