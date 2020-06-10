class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
    	int i, j, n = nums.size();
    	int maxlen = 1, sum = 0;
    	vector<int> dp(n, 1);
        vector<int> count(n, 1);
    	for(i = 1; i < n; ++i)
    	{
    		for(j = i-1; j >= 0; --j)
    		{
    			if(nums[i] > nums[j])
    			{
                    if(dp[j]+1 > dp[i])
                    {
                        dp[i] = dp[j]+1;
                        count[i] = count[j];
                    }
                    else if(dp[j]+1 == dp[i])
                        count[i] += count[j];
                }
    		}
            maxlen = max(maxlen, dp[i]);
    	}
        for(i = 0; i < n; ++i)
            if(dp[i]==maxlen)
                sum += count[i];
        return sum;
    }
};