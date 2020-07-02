class Solution {
public:
    int minCost(vector<vector<int>>& costs) {
    	int n = costs.size(), house, color;
        if(n==0) return 0;
    	vector<vector<int>> dp(n,vector<int>(3,INT_MAX));
    	dp[0] = costs[0];
    	for(house = 1; house < n; house++)
    	{
    		for(color = 0; color < 3; ++color)
    		{
    			dp[house][color] = min(dp[house][color], costs[house][color]+min(dp[house-1][(color+1)%3], dp[house-1][(color+2)%3]));
    		}
    	}
    	return min(dp[n-1][0], min(dp[n-1][1], dp[n-1][2]));
    }
};