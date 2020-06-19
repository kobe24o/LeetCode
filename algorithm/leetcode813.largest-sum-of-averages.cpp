class Solution {	//C++
public:
    double largestSumOfAverages(vector<int>& A, int K) {
    	int i, j, k, n = A.size();
    	vector<vector<double>> dp(n,vector<double>(K+1, 0.0));
    	//dp[i][k] 表示，以i结束的时候，切分了k次，所有平均值和的最大值
    	vector<int> presum(A);
    	for(i = 1; i < n; i++) 
    		presum[i] += presum[i-1];
    	for(i = 0; i <= n-K; ++i)
    		dp[i][1] = presum[i]/double(i+1);//初始化，切1段出来的平均值
    	for(k = 2; k <= K; ++k)
    	{	//切第k次
    		for(j = k-1; j < n-(K-k); ++j)
    		{	//j 第k次可能的范围
    			for(i = j-1; i >= 0; --i)
    			{	//遍历小于 j 的所有 i
    				dp[j][k] = max(dp[j][k], dp[i][k-1]+(presum[j]-presum[i])/double(j-i));
    			}
    		}
    	}
    	return dp[n-1][K];
    }
};