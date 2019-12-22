class Solution {
public:
    int minSteps(int n) {
        vector<int> dp(n+1,0);
        int i, j;
        for(i = 2; i <= n ; ++i)
        {
        	dp[i] = i;	//一直粘贴的次数
        	for(j = 2; j < i; ++j)
        	{
        		if(i%j == 0)
        			dp[i] = min(dp[i], dp[j]+i/j);
        	}
        }
        return dp[n];
    }
};