class Solution {
public:
    int checkRecord(int n) {
        int ans = 0, mod = 1e9+7;
        vector<vector<long long>> dp(n, vector<long long>(13, 0));
        // APLL, 4个二进制位, 表示结尾出现字符的情况
        // 8421
        dp[0][8] = 1; // A结尾
        dp[0][4] = 1; // P结尾
        dp[0][1] = 1; // L结尾
        for(int i = 1; i < n; i++) 
        {
            // A结尾, 原来可能是 P,L,LL结尾
            dp[i][8] += (dp[i-1][4]+dp[i-1][1]+dp[i-1][2])%mod;
            // P结尾，原来没有A, 原来结尾可能是 P, L, LL
            dp[i][4] += (dp[i-1][4]+dp[i-1][1]+dp[i-1][2])%mod;
            // P结尾，原来有A, 原来结尾可能是 A, P, L, LL
            dp[i][12] += (dp[i-1][8]+dp[i-1][12]+dp[i-1][9]+dp[i-1][10])%mod;
            // L结尾，原来没有A, 原来结尾可能是 P
            dp[i][1] += dp[i-1][4]%mod;
            // L结尾，原来有A, 原来结尾可能是 A, P
            dp[i][9] += (dp[i-1][8]+dp[i-1][12])%mod;
            // LL结尾，原来没有A, 原来结尾可能是 L
            dp[i][2] += dp[i-1][1]%mod;
            // LL结尾，原来有A, 原来结尾可能是 L
            dp[i][10] += dp[i-1][9]%mod;
        }
        for(int i = 1; i <= 12; i++)
            ans = (ans+dp[n-1][i])%mod;
        return ans;
    }
};