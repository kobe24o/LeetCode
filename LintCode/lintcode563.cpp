class Solution {
public:
    int backPackV(vector<int> &nums, int target) {
        if(nums.size() == 0)
            return 0;
        if(target == 0)
            return 1;
        int n = nums.size(), i, j;
        vector<vector<int>> dp(n,vector<int>(target+1, 0));
        dp[0][0] = 1;//第一个物品不放
        if(nums[0] <= target)
            dp[0][nums[0]] = 1;//第一个物品放，1种方案
        for(i = 1; i < n; i++)//遍历剩余的物品
        {
            for(j = 0; j <= target; j++)
            {
                if(dp[i-1][j] != 0)//上一行所有存在的状态
                {
                    dp[i][j] += dp[i-1][j];//i个物品不放
                    if(j <= target-nums[i])//i个物品放进去不超重
                        dp[i][j+nums[i]] += dp[i-1][j];
                }
            }
        }
        return dp[n-1][target];
    }
};