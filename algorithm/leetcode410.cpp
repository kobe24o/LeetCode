class Solution {
public:
    int splitArray(vector<int>& nums, int m) {
    	long long l = 0, r = 1e15, maxsum, ans;
    	while(l <= r)
    	{
    		maxsum = l+((r-l)>>1);
    		if(canSplitM(nums, maxsum, m))
    			r = maxsum-1, ans = maxsum;
    		else
    			l = maxsum+1;
    	}
    	return ans;
    }
    bool canSplitM(vector<int>& nums, long long maxsum, int m) 
    {
    	int count = 0;
    	long long sum = 0;
    	for(int i = 0; i < nums.size(); ++i)
    	{
    		if(sum+nums[i] <= maxsum)
    			sum += nums[i];
    		else
    		{
    			count++;
    			sum = 0;
    			i--;
    		}
    		if(count >= m)
    			return false;
    	}
    	return true;
    }
};

class Solution {
public:
    int splitArray(vector<int>& nums, int m) {
        int n = nums.size(), i, j, k;
        vector<long long> sum(n+1, 0);
        for(i = 1; i <= n; ++i)
            sum[i] = sum[i-1] + nums[i-1];
        vector<vector<long long>> dp(n+1, vector<long long>(m+1,1e15));
        dp[0][0] = 0;
        for(i = 1; i <= n; ++i)
            for(j = 1; j <= min(i,m); ++j)
                for(k = 0; k < i; ++k)
                    dp[i][j] = min(dp[i][j], max(dp[k][j-1], sum[i]-sum[k]));
        return dp[n][m];
    }
};