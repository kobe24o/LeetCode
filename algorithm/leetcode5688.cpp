class Solution {
public:
    int longestPalindrome(string word1, string word2) {
        string s = word1 + word2;
        int n = s.size(), n1 = word1.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        int ans = 0;
        for(int i = 0; i < n; ++i)
        {
            dp[i][i] = 1;
            for(int j = i-1; j >= 0; --j)
            {
                if(s[i] == s[j])
                {
                    dp[j][i] = dp[j+1][i-1]+2;
                    if(j < n1 && i >= n1)
                        ans = max(ans, dp[j][i]);
                }
                else
                    dp[j][i] = max(dp[j+1][i], dp[j][i-1]); 
            }
        }
        return ans;
    }
};