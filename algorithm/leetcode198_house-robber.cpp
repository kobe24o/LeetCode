class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size(), i;
        if(n == 0)
        	return 0;
        else if(n == 1)
        	return nums[0];
        else if(n == 2)
        	return max(nums[0],nums[1]);
        int dp[n] = {0};
        dp[0] = nums[0];
        dp[1] = max(nums[0],nums[1]);
        for(i = 2; i < n; ++i)
        {
        	dp[i] = max(dp[i-2]+nums[i], dp[i-1]);
        }
        return dp[n-1];
    }
};

class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size(), i;
        if(n == 0)
        	return 0;
        else if(n == 1)
        	return nums[0];
        else if(n == 2)
        	return max(nums[0],nums[1]);
        int dp_i, dp_i_2 = nums[0], dp_i_1 = max(nums[0],nums[1]);
        for(i = 2; i < n; ++i)
        {
        	dp_i = max(dp_i_2+nums[i], dp_i_1);
        	dp_i_2 = dp_i_1;
        	dp_i_1 = dp_i;
        }
        return dp_i;
    }
};