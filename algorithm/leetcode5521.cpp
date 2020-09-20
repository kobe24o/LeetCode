typedef long long ll;
class Solution {
public:
    int maxProductPath(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<pair<ll,ll>>> dp(m, vector<pair<ll,ll>>(n));
        dp[0][0].first = dp[0][0].second =  grid[0][0];
        // first 存储最小值，second 存储最大值
        for(int i = 1; i < n; ++i) //初始化第一行
        {
            if(grid[0][i] == 0)
                dp[0][i].first = dp[0][i].second = 0;
            else if(grid[0][i] > 0)
            {
                dp[0][i].first = dp[0][i-1].first*grid[0][i];
                dp[0][i].second = dp[0][i-1].second*grid[0][i];
            }
            else if(grid[0][i] < 0)
            {
                dp[0][i].first = dp[0][i-1].second*grid[0][i];
                dp[0][i].second = dp[0][i-1].first*grid[0][i];
            }
        }
        for(int i = 1; i < m; ++i)  //初始化第一列
        {
            if(grid[i][0] == 0)
                dp[i][0].first = dp[i][0].second = 0;
            else if(grid[i][0] > 0)
            {
                dp[i][0].first = dp[i-1][0].first*grid[i][0];
                dp[i][0].second = dp[i-1][0].second*grid[i][0];
            }
            else if(grid[i][0] < 0)
            {
                dp[i][0].first = dp[i-1][0].second*grid[i][0];
                dp[i][0].second = dp[i-1][0].first*grid[i][0];
            }
        }
        for(int i = 1; i < m; i++)
        {
            for(int j = 1; j < n; j++)
            {
                if(grid[i][j] == 0)
                    dp[i][j].first = dp[i][j].second = 0;
                else if(grid[i][j] > 0)
                {
                    dp[i][j].first = min(dp[i-1][j].first, dp[i][j-1].first)*grid[i][j];
                    dp[i][j].second = max(dp[i-1][j].second, dp[i][j-1].second)*grid[i][j];
                }
                else if(grid[i][j] < 0)
                {
                    dp[i][j].second = min(dp[i-1][j].first, dp[i][j-1].first)*grid[i][j];
                    dp[i][j].first = max(dp[i-1][j].second, dp[i][j-1].second)*grid[i][j];
                }
            }
        }
        if(dp[m-1][n-1].second < 0)
            return -1;
        return dp[m-1][n-1].second%(int(1e9+7));
    }
};