class Solution {
public:
    int distinctSubseqII(string S) {
        int n = S.size(), mod = 1e9+7, ans = 0;
        vector<vector<int>> dp(n+1, vector<int>(26,0));
        // 到 第 i 个字符为止，以a-z 某字符结束的子序个数
        for(int i = 1; i <= n; i++)
        {
            int sum = 0;
            for(int j = 0; j < 26; j++)
            {
                if(S[i-1]-'a' != j)
                    dp[i][j] = dp[i-1][j];
                sum = (sum+dp[i-1][j])%mod;
            }
            dp[i][S[i-1]-'a'] = (sum+1)%mod;
        }
        for(int i = 0; i < 26; ++i)
            ans = (ans+dp[n][i])%mod;
        return ans;
    }
};

class Solution {
public:
    int distinctSubseqII(string S) {
        int n = S.size(), mod = 1e9+7;
        vector<int> dp(n+1, 0);
        dp[0] = 1;//空字符串
        vector<int> prev(26, -1);
        for(int i = 0; i < n; i++) 
        {
            dp[i+1] = (dp[i]*2)%mod;
            if(prev[S[i]-'a'] != -1)
                dp[i+1] = (dp[i+1]-dp[prev[S[i]-'a']]+mod)%mod;
            prev[S[i]-'a'] = i;
        }
        return dp[n]-1;
    }
};