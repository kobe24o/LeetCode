class Solution {
public:
    int countVowelStrings(int n) {
        vector<vector<int>> dp(n+1, vector<int>(5, 0));
        dp[1][0] = dp[1][1] = dp[1][2] = dp[1][3] = dp[1][4] = 1;
        for(int i = 2; i <= n; ++i)
        {
            for(int j = 0; j < 5; ++j)
            {
                for(int k = j; k < 5; ++k)
                {
                    dp[i][k] += dp[i-1][j];
                }
            }
        }
        int ans = 0;
        for(int i = 0; i < 5; ++i)
            ans += dp[n][i];
        return ans;
    }
};