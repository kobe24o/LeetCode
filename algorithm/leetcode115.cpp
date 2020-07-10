class Solution {
public:
    int numDistinct(string s, string t) {
        if(t=="") return 1;
        if(s.size() < t.size()) return 0;
        int m = s.size(), n = t.size(), i, j;
        vector<vector<long>> dp(m+1, vector<long>(n+1,0));
        for(i = 0; i <= m; ++i)
            dp[i][0] = 1;
        for(j = 1; j <= n; j++)
        {
            for(i = 1; i <= m; i++)
            {
                if(s[i-1]==t[j-1])
                    dp[i][j] = dp[i-1][j-1]+dp[i-1][j];
                else
                    dp[i][j] = dp[i-1][j];
            }
        }
        return dp[m][n];
    }
};