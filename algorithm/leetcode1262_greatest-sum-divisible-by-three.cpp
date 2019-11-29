class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
        int i, j, idx, n = nums.size();
        int dp[n][3];//列存放余数为0,1,2的和
        memset(dp,0,sizeof dp);
        dp[0][nums[0]%3] = nums[0];
        for(i = 1; i < n; ++i)
        {
        	idx = nums[i]%3;
        	for(j = 0; j < 3; ++j)
        		dp[i][(idx+j)%3] = dp[i-1][j]+nums[i];
        }
        return dp[n-1][0];
    }
};