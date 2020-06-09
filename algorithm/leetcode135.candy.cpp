class Solution {
public:
    int candy(vector<int>& ratings) {
    	int i, j, n = ratings.size(), sum = 0;
    	vector<int> dp(n,1);
    	for(i = 1, j = n-2; i < n && j >= 0; ++i,--j)
    	{
    		if(ratings[i] > ratings[i-1])
    			dp[i] = max(dp[i], dp[i-1]+1);
            if(ratings[j] > ratings[j+1])
                dp[j] = max(dp[j], dp[j+1]+1);
    	}
        for(i = 0; i < n; ++i)
            sum += dp[i];
    	return sum;
    }
};