class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size(), i;
        int dp[n] = {0};
        dp[0] = cost[0];
        dp[1] = cost[1];
        for(i = 2; i < n; ++i)
        	dp[i] = cost[i]+min(dp[i-1],dp[i-2]);
        return min(dp[n-2],dp[n-1]);
    }
};

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size(), i, dp_i;
        int dp_i_2 = cost[0];
        int dp_i_1 = cost[1];
        for(i = 2; i < n; ++i)
        {
        	dp_i = cost[i]+min(dp_i_1,dp_i_2);
        	dp_i_2 = dp_i_1;
        	dp_i_1 = dp_i;
        }
        return min(dp_i_1,dp_i_2);
    }
};