class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
    	int i, j, n = stones.size(), sum = accumulate(stones.begin(),stones.end(), 0);
    	vector<vector<bool>> dp(n+1,vector<bool>(sum/2+1, false));
    	dp[0][0] = true;//dp[i][w], 遍历完第i个石头，可以剩余的重量为w吗？
    	for(i = 1; i <= n; i++)//样本维度
    	{
    		for(j = 0; j <= sum/2; ++j)//重量维度
    		{
    			if(dp[i-1][j])
    			{
    				dp[i][j] = dp[i-1][j];
    				if(j+stones[i-1] <= sum/2)
    					dp[i][j+stones[i-1]] = true;
    			}
    		}
    	}
    	j = sum/2;
    	while(dp[n][j] != true)
    		j--;
    	return sum-2*j;
    }
};

class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
    	int i, j, n = stones.size(), sum = accumulate(stones.begin(),stones.end(), 0);
    	vector<bool> dp(sum/2+1, false);
    	dp[0] = true;//dp[w], 遍历完第i个石头，可以剩余的重量为w吗？
    	for(i = 0; i < n; i++)//样本维度
    	{
    		for(j = sum/2; j >= 0; --j)//重量维度
    		{
    			if(dp[j] && j+stones[i] <= sum/2)
    				dp[j+stones[i]] = true;
    		}
    	}
    	j = sum/2;
    	while(dp[j] != true)
    		j--;
    	return sum-2*j;
    }
};