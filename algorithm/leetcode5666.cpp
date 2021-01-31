class Solution {
public:
    bool checkPartitioning(string s) {
        int n = s.size();
        vector<vector<bool>> dp(n, vector<bool>(n,false));
        dp[0][0] = true;
        for(int i = 1; i < n; i++)
        {
            dp[i][i] = true;// [i, j] 区间是不是回文
            if(s[i-1] == s[i])
                dp[i-1][i] = true;
        }
        for(int len = 2; len < n; len++)
        {
            for(int i = 0, j; i+len < n; i++)
            {
                j = i + len;
                if(s[i]==s[j] && dp[i+1][j-1])
                    dp[i][j] = true;
            }
        }
        for(int i = 0; i < n-2; i++) // [0, i] [i+1, j] [j+1, n-1]
        {
            for(int j = i+1; j < n-1; j++)
            {
                if(dp[0][i] && dp[i+1][j] && dp[j+1][n-1])
                    return true;
            }
        }
        return false;
    }
};