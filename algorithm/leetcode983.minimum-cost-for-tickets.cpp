class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        vector<int> dp(366,INT_MAX);//dp[i]表示第i天花的最少的钱
        int d[3] = {1,7,30};//票的有效期
        int i, j, k, n = days.size();
        for(i = 0; i < 3; ++i)//初始化，第一天的选择，3种选择
            for(j = days[0]; j < min(366,days[0]+d[i]); ++j)
            {	//后面的天都不用再花钱，重叠的时间，取最小的花费
                dp[j] = min(dp[j], costs[i]);
            }
        for(i = 1; i < n; ++i)
        {	//遍历从第2天开始的其余的天
            for(k = 0; k < 3; ++k)//三种票选择
                for(j = days[i]; j < min(366,days[i]+d[k]); ++j)
                {	//上一次花的钱是 dp[days[i-1]],这次花的钱costs[k]
                    dp[j] = min(dp[j], dp[days[i-1]]+costs[k]);
                }
        }
        return dp[days[n-1]];//最后一次的最小花费
    }
};