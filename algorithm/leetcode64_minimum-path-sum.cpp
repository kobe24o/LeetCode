#include<vector>
using namespace std;
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int dp[m][n], i, j;
        dp[0][0] = grid[0][0];
        for(i = 1; i < n; i++)
        	dp[0][i] = dp[0][i-1] + grid[0][i];
        for(i = 1; i < m; i++)
            dp[i][0] = dp[i-1][0] + grid[i][0];
        for(i = 1; i < m; i++)
            for(j = 1; j < n; j++)
            {
                dp[i][j] = grid[i][j] + min(dp[i][j-1],dp[i-1][j]);
            }
        return dp[m-1][n-1];
    }
};