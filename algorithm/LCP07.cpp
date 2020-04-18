class Solution {
public:
    int numWays(int n, vector<vector<int>>& relation, int k) {
    	set<vector<int>> s;
    	for(auto re : relation)
			s.insert(re);

		vector<vector<int>> dp(k+1,vector<int>(n,0));
		dp[0][0] = 1;//初始状态
		for(int i = 1; i <= k; ++i)//k次传递
		{
			for(int j = 0; j < n; ++j)
			{	//n个人，如果存在传递到这的情况
				if(dp[i-1][j]!=0)
				{
					for(int k = 0; k < n; ++k)
					{	//传给下一个人，可以传给跟自己有关系的
						if(s.count({j,k}))//有关系
							dp[i][k] += dp[i-1][j];
					}
				}
			}
		}
		return dp[k][n-1];
	}	
};