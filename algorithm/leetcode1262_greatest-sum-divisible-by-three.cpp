class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
        int i, j, idx, n = nums.size();
        int dp[n][3];//列存放余数为0,1,2的和
        memset(dp,0,sizeof dp);
        dp[0][nums[0]%3] = nums[0];
        for(i = 1; i < n; ++i)
        {
        	for(j = 0; j < 3; ++j)
        		dp[i][j] = dp[i-1][j];
        	for(j = 0; j < 3; ++j)
        	{
        		idx = (dp[i-1][j]+nums[i])%3;
        		dp[i][idx] = max(dp[i][idx], dp[i-1][j]+nums[i]);
        	}
        }
        return dp[n-1][0];
    }
};