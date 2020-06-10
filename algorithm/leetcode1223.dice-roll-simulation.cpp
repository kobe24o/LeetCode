class Solution {	//C++
public:
    int dieSimulator(int n, vector<int>& rollMax) {
    	vector<vector<vector<int>>> dp(n,vector<vector<int>>(6,vector<int>(16,0)));
    	int i,j,nj,k;
    	for(j = 0; j < 6; ++j)
    	{	//初始化
    		dp[0][j][1] = 1;//0次投出j点，j连续了1次的方案数
    	}
    	for(i = 1; i < n; ++i)
    	{	//后序的样本
    		for(j = 0; j < 6; ++j)
    		{	//前一次投出的点数
    			for(k = 1; k <= 15; ++k)
    			{	//前一次的最后的点数连续了几次
    				if(dp[i-1][j][k] != 0)
    				{	//状态存在
    					for(nj = 0; nj < 6; ++nj)
    					{	//这一次投的点数
    						if(nj == j && k+1 <= rollMax[j])//跟上一次一样的点且连续次数不超
    							dp[i][nj][k+1] = (dp[i][nj][k+1]+dp[i-1][j][k])%1000000007;
    						if(nj != j)//跟上一次不一样，连续次数变为1次
    							dp[i][nj][1] = (dp[i][nj][1]+dp[i-1][j][k])%1000000007;
    					}
    				}
    			}
    		}
    	}
    	int sum = 0;
    	for(j = 0; j < 6; ++j)
    	{	//求和
    		for(k = 1; k <= 15; ++k)
    			sum = (sum+dp[n-1][j][k])%1000000007;
    	}
    	return sum;
    }
};