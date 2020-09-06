class Solution {
public:
    int countRoutes(vector<int>& locations, int start, int finish, int fuel) {
    	int n = locations.size(), i, j, f, mod = 1e9+7;
    	vector<vector<int>> dp(n, vector<int>(fuel+1, 0));
    	dp[start][0] = 1; // 到达 i 城市，花了 f 油的方案数
		for(f = 0; f <= fuel; ++f)
		{
			for(i = 0; i < n; ++i)
			{
				for(j = 0; j < n; ++j)
				{
					if(i == j)
						continue;
					if(dp[i][f] != 0 && f+abs(locations[i]-locations[j]) <= fuel)
					{
						dp[j][f+abs(locations[i]-locations[j])] += dp[i][f];
						dp[j][f+abs(locations[i]-locations[j])] %= mod;
					}
				}
			}
		}
		int ans = 0;
		for(f = 0; f <= fuel; f++)
			ans = (ans+dp[finish][f])%mod;
		return ans;
    }
};