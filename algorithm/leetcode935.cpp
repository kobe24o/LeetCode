class Solution {
public:
    int knightDialer(int n) {
        long long dp[10][5001];
        int mod = 1e9+7;
        memset(dp, 0, sizeof(dp));
        dp[0][n-1] = dp[1][n-1] = dp[2][n-1] = dp[3][n-1] = dp[4][n-1]
        = dp[5][n-1] = dp[6][n-1] = dp[7][n-1] = dp[8][n-1] = dp[9][n-1] = 1;
        for(int k = n-1; k > 0; k--) 
        {
            dp[0][k-1] += (dp[4][k]%mod)+(dp[6][k]%mod);
            dp[1][k-1] += (dp[6][k]%mod)+(dp[8][k]%mod);
            dp[2][k-1] += (dp[7][k]%mod)+(dp[9][k]%mod);
            dp[3][k-1] += (dp[4][k]%mod)+(dp[8][k]%mod);
            dp[4][k-1] += (dp[3][k]%mod)+(dp[0][k]%mod)+(dp[9][k]%mod);
            // dp[5][k-1] = 0; // 不能转移
            dp[6][k-1] += (dp[1][k]%mod)+(dp[0][k]%mod)+(dp[7][k]%mod);
            dp[7][k-1] += (dp[2][k]%mod)+(dp[6][k]%mod);
            dp[8][k-1] += (dp[1][k]%mod)+(dp[3][k]%mod);
            dp[9][k-1] += (dp[4][k]%mod)+(dp[2][k]%mod);
        }
        int ans = 0;
        for(int i = 0; i < 10; i++)
            ans = (ans+dp[i][0])%mod;
        return ans;
    }
};