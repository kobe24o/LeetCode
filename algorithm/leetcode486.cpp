class Solution {
public:
    bool PredictTheWinner(vector<int>& nums) {
    	int n = nums.size(), i, j;
    	vector<vector<int>> dp(n, vector<int>(n, INT_MIN));
    	for(i = 0; i < n; ++i)
    		dp[i][i] = nums[i];
    	for(int len = 1; len < n; ++len)
    	{
    		for(i = 0; i+len < n; ++i)
    		{
    			dp[i][i+len] = max(nums[i]-dp[i+1][i+len], nums[i+len]-dp[i][i+len-1]);
    		}
    	}
    	return dp[0][n-1] >= 0;
    }
};