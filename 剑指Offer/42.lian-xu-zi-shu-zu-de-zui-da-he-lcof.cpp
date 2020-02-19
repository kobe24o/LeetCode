class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int i, n = nums.size(), ans = nums[0];
        vector<int> dp(n,0);
        dp[0] = nums[0];
        for(i = 1; i < n; ++i)
        {
        	if(dp[i-1] >= 0)
        		dp[i] = nums[i]+dp[i-1];
        	else
        		dp[i] = nums[i];
        	ans = max(ans,dp[i]);
        }
        return ans;
    }
};