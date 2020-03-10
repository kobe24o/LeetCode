class Solution {
public:
    int nthUglyNumber(int n) {
        int dp[n+1] = {0};
        dp[1] = 1;
        int i2=1, i3=1, i5=1;
        for(int i = 2; i <= n; i++)
        {
        	dp[i] = min(dp[i2]*2, min(dp[i3]*3, dp[i5]*5));
        	if(dp[i2]*2 == dp[i])
        		i2++;
        	if(dp[i3]*3 == dp[i])
        		i3++;
        	if(dp[i5]*5 == dp[i])
        		i5++;
        }
        return dp[n];
    }
};
