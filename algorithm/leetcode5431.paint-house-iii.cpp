class Solution {
public:
    int minCost(vector<int>& houses, vector<vector<int>>& cost, int m, int n, int target) {
        int i, j, c1, c2, mincost = INT_MAX;
        vector<vector<vector<int>>> dp(m, vector<vector<int>>(n+1, vector<int>(m+1, INT_MAX)));
        for(c1 = 0; c1 < n; ++c1)
            if(houses[0])
                dp[0][c1][1] = cost[0][c1];
            else
                dp[0][c1][1] = 0;
        //第0个房子，喷涂的c1颜色，形成了1个block的最小花费
        for(i = 1; i < m; i++) 
        {
            for(c1 = 0; c1 < n+1; c1++)//前一个房子的颜色
            {
                for(j = 1; j < m; j++)//几个 block
                {
                    if(dp[i-1][c1][j] == INT_MAX)
                        continue;
                    if(houses[i] != 0)//已经刷过颜色
                    {
                        if(houses[i] == c1)
                            dp[i][houses[i]][j] = min(dp[i][houses[i]][j], dp[i-1][c1][j]);
                        else
                            dp[i][houses[i]][j+1] = min(dp[i][houses[i]][j+1], dp[i-1][c1][j]);
                    }
                    else//没有刷过颜色
                        for(c2 = 0; c2 < n+1; c2++)//当前房子的颜色
                        {
                            if(c1 == c2)//跟前一家颜色一样
                            {
                                dp[i][c2][j] = min(dp[i][c2][j], dp[i-1][c1][j]+cost[i-1][c2-1]);
                            }
                            else
                                dp[i][c2][j+1] = min(dp[i][c2][j+1], dp[i-1][c1][j]+cost[i-1][c2-1]);
                        }
                }
            }
        }
        for(c1 = 0; c1 < n+1; c1++)
            mincost = min(mincost, dp[m-1][c1][target]);
        return mincost;
    }
};