class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size(), i, m1, m2;
        if(n == 0)
        	return 0;
        else if(n == 1)
        	return nums[0];
        else if(n == 2)
        	return max(nums[0],nums[1]);
        int dp[n] = {0};
        //第一间房子，偷，那么最后一间n-1不能偷
        dp[0] = nums[0];
        dp[1] = max(nums[0],nums[1]);
        for(i = 2; i <= n-2; ++i)
        {
        	dp[i] = max(dp[i-2]+nums[i], dp[i-1]);
        }
        m1 = dp[n-2];
        //第一间房子，不偷，那么最后一间n-1能偷
        dp[1] = nums[1];
        dp[2] = max(nums[1],nums[2]);
        for(i = 3; i <= n-1; ++i)
        {
        	dp[i] = max(dp[i-2]+nums[i], dp[i-1]);
        }
        m2 = dp[n-1];
        return max(m1,m2);
    }
};
