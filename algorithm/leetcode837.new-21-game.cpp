class Solution {
public:
    double new21Game(int N, int K, int W) {
    	vector<double> dp(N+1, 0.0);
        if(K == 0 || N >= K + W) return 1.0;//肯定不会超出N
    	dp[0] = 1;
    	double prob = 1.0;//停在 i前面 w个位置的概率之和， 初值在0位置概率为1
    	int i;
    	for(i = 1; i < K; ++i)//小于K时，可以继续，w个前缀可以加上本次的概率
    	{
            if(i <= W)
    		{
                dp[i] = prob/W;//前面所有的位置都可以到此处，每个位置乘以1/w
    		    prob += dp[i];//前缀概率和，+本次
            }
            else	//超过w个了
            {
                dp[i] = (prob-dp[i-W-1])/W;//不在窗口内的，不能到i处了，需要减去
    		    prob += dp[i] - dp[i-W-1];//前缀+本次，-不在窗口内的
            }
    	}

    	for( ; i >= K && i <= N; ++i)// >= K 了， 不能再走了，不加本次的概率
    	{
            if(i <= W)
    		    dp[i] = prob/W;
            else
            {
                dp[i] = (prob-dp[i-W-1])/W;
                prob -= dp[i-W-1];//不加本次的概率，在窗口w外的减去
            }
    	}
    	for(i = K, prob = 0.0; i <= N; ++i)
    		prob += dp[i];
    	return prob;
    }
};