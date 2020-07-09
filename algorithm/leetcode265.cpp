class Solution {
public:
    int minCostII(vector<vector<int>>& costs) {
        if(costs.size()==0 || costs[0].size()==0)
            return 0;
        int m = costs.size(), n = costs[0].size(), i, c1 = -1, c2, mincolor;
        int prevmin1 = 0, prevmin2 = 0, cost, curmin1, curmin2;
        for(i = 0; i < m; ++i)
        {
            curmin1 = curmin2 = INT_MAX;
            for(c2 = 0; c2 < n; ++c2)
            {
                cost = (c2==c1 ? costs[i][c2]+prevmin2 : costs[i][c2]+prevmin1);
                if(cost <= curmin1)
                {
                    curmin2 = curmin1;
                    curmin1 = cost;
                    mincolor = c2;
                }
                else if(cost < curmin2)
                    curmin2 = cost;
            }
            prevmin1 = curmin1;
            prevmin2 = curmin2;
            c1 = mincolor;
        }
        return prevmin1;
    }
};
class Solution {
public:
    int minCostII(vector<vector<int>>& costs) {
        if(costs.size()==0 || costs[0].size()==0)
            return 0;
        int m = costs.size(), n = costs[0].size(), i, c1, c2;
        vector<vector<int>> dp(m,vector<int>(n,INT_MAX));
        dp[0] = costs[0];
        for(i = 1; i < m; ++i)
        {
            for(c1 = 0; c1 < n; ++c1)
            {
                for(c2 = 0; c2 < n; ++c2)
                {
                    if(c1==c2)
                        continue;
                    dp[i][c2] = min(dp[i][c2], dp[i-1][c1]+costs[i][c2]);
                }
            }
        }
        int mincost = INT_MAX;
        for(i = 0; i < n; ++i)
            mincost = min(mincost, dp[m-1][i]);
        return mincost;
    }
};