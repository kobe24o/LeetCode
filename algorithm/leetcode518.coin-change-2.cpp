class Solution {
public:
    int change(int amount, vector<int>& coins) {
    	int i, j, n = coins.size();
    	vector<int> dp(amount+1,0);
    	dp[0] = 1;
        for(i = 0; i < n; ++i)
        {
            for(j = 0; j <= amount; ++j)
                if(dp[j] != 0 && j+coins[i] <= amount)
                    dp[j+coins[i]] += dp[j];
        }
    	return dp[amount];
    }
};