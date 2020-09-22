class Solution {
public:
    int findPaths(int m, int n, int N, int i, int j) {
        if(N == 0)
            return 0;
    	vector<vector<vector<int>>> dp(m,vector<vector<int>>(n, vector<int>(N+1, 0)));
    	int x, y, k, ans = 0, mod = 1e9+7;
    	vector<vector<int>> dir = {{1,0},{0,1},{0,-1},{-1,0}};
    	for(y = 0; y < n; y++)
    	{
    		dp[0][y][N-1] += 1;
    		dp[m-1][y][N-1] += 1;
    	}
    	for(x = 0; x < m; x++)
    	{
    		dp[x][0][N-1] += 1;
    		dp[x][n-1][N-1] += 1;
    	}
    	ans = (ans+dp[i][j][N-1])%mod;
    	int t = N-1;
    	while(t)
    	{
    		vector<vector<vector<int>>> temp(m,vector<vector<int>>(n, vector<int>(N+1, 0)));
    		for(x = 0; x < m; x++)
    		{
    			for(y = 0; y < n; y++)
    			{
    				temp[x][y][t-1] = (temp[x][y][t-1] + (x > 0 ? dp[x-1][y][t] : 0))%mod;
    				temp[x][y][t-1] = (temp[x][y][t-1] + (y > 0 ? dp[x][y-1][t] : 0))%mod;
    				temp[x][y][t-1] = (temp[x][y][t-1] + (x < m-1 ? dp[x+1][y][t] : 0))%mod;
    				temp[x][y][t-1] = (temp[x][y][t-1] + (y < n-1 ? dp[x][y+1][t] : 0))%mod;
    			}
    		}
            ans = (ans+temp[i][j][t-1])%mod;
            t--;
    		dp = temp;
    	}
    	return ans;
    }
};