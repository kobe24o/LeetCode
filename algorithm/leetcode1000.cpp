class Solution {
public:
    int mergeStones(vector<int>& stones, int K) {
    	int n = stones.size();
    	if((n-1)%(K-1) != 0) return -1;
    	vector<vector<int>> dp(n+1, vector<int>(n+1, INT_MAX));
    	vector<int> sum(n+1, 0);
    	for(int i = 1; i <= n; i++)
    		sum[i] = stones[i-1] + sum[i-1];//前缀和
    	for(int i = 1; i+K-1 <= n; ++i)
    		dp[i][i+K-1] = sum[i+K-1]-sum[i-1];
    	int c = (n-1)/(K-1);//合并的次数
    	for(int t = 2; t <= c; t++)
    	{	//第几次合并
    		for(int i = 1; i+t*(K-1) <= n; i++)
    		{	//要获得区间[i, i+t*K-1]的最优值
    			int r = i+t*(K-1);
    			for(int j = 0; j < K+1; j++)//在上一次的结果里，遍历 K+1 种情况
    			{
    				dp[i][r] = min(dp[i][r], 
			    					dp[i+j][r-(K-j)]
			    					+(-sum[i-1])
			    					+(sum[r]));
    			}
    		}
    	}
    	return dp[1][n];
    }
};