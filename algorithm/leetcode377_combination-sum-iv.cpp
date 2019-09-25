class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        unsigned long long dp[target+1] = {0}, i, j;
        dp[0] = 1;
        for(i = 1; i <= target; i++)
        {
        	for(j = 0; j < nums.size(); j++)
        	{
        		if(i >= nums[j])
        			dp[i] = dp[i]+dp[i-nums[j]];
        	}
        }
        return dp[target];
    }
};