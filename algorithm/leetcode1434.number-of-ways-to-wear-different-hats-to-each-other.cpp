class Solution {
public:
    int numberWays(vector<vector<int>>& hats) {
    	int i, state, mod = 1e9+7, n = hats.size();//n个人
    	int N = (1<<n);//n个人带帽子或不戴帽子有2^n种可能(这个维度比较小n最大10)
    	vector<vector<long long>> dp(41,vector<long long>(N,0));
    	//dp[i][j]表示戴上第i个帽子后，人们戴帽子状态为 j(拆成二进制位0没戴，1戴了)的戴帽子方案数
    	//初始化
    	dp[0][0] = 1;//都没戴帽子1种情况
    	vector<set<int>> hat_p(41);//某个帽子可以戴的人
    	for(i = 0; i < n; ++i)
    		for(int hat : hats[i])
    			hat_p[hat].insert(i);
		for(i = 1; i <= 40; ++i)//遍历每个帽子
		{
            dp[i] = dp[i-1];
			for(int p : hat_p[i])//该帽子可以戴的人p
			{
				for(state = 0; state < N; ++state)
				{
					if(((((state-(1<<p)))>>p)&1)==0)
					{   //到达state状态之前的状态state-(1<<p)中，p号人没有戴帽子
						dp[i][state] += dp[i-1][state-(1<<p)];
					}
				}
			}
		}
		return dp[40][N-1]%mod;
    }
};