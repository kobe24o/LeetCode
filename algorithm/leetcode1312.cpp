class Solution {
public:
    int minInsertions(string s) {
        int n = s.size();
        vector<vector<int>> dp(n,vector<int>(n, 0));
        for(int i = 1; i < n; i++) 
        {
            if(s[i-1] != s[i])
                dp[i-1][i] = 1;
        }
        for(int len = 2; len < n; len++)
        {
            for(int i = 0; i+len < n; i++)
            {
                int j = i+len;
                if(s[i]==s[j])
                    dp[i][j] = dp[i+1][j-1];
                else
                {
                    dp[i][j] = min(2+dp[i+1][j-1], 1 + min(dp[i+1][j], dp[i][j-1]));
                }
            }
        }
        return dp[0][n-1];
    }
};