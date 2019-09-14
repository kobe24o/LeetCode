class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        nums.insert(nums.begin(),1);//首尾加入虚拟的气球
        nums.push_back(1);
        vector<vector<int>> dp(n+2,vector<int>(n+2,0));
        int len, i, j, k;
        for(len = 1; len <= n; ++len) 
        {
        	for(i = 1; i <= n-len+1; ++i)
        	{
        		j = len+i-1;
        		for(k = i; k <= j; ++k)
        		{
        			dp[i][j] = max(dp[i][j],dp[i][k-1]+dp[k+1][j]+nums[i-1]*nums[k]*nums[j+1]);
        		}
        	}
        }
        return dp[1][n];
    }
};