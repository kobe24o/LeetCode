class Solution {
public:
    int palindromePartition(string s, int k) {
        int n = s.size();
        vector<vector<int>> cost(n, vector<int>(n, 0));
        for(int i = 0; i < n-1; i++)
            if(s[i] != s[i+1])
                cost[i][i+1] = 1;
        for(int len = 2; len <= n; len++) 
        {
            for(int i = 0, j; i+len < n; i++)
            {
                j = i+len;
                cost[i][j] = (s[i] == s[j] ? cost[i+1][j-1] : 1+cost[i+1][j-1]);
            }
        }
        vector<vector<int>> dp(n+1, vector<int>(k+1, INT_MAX));
        // dp[0][0] = 0;
        for(int i = 1; i <= n; i++)
        {
            for(int K = 1; K <= min(i, k); K++)
            {
                if(K==1)//分成1一个串
                    dp[i][K] = cost[0][i-1];
                else// 分成 k 个串
                {
                    for(int j = K-1; j < i; j++)
                    {
                        dp[i][K] = min(dp[i][K], dp[j][K-1]+cost[j][i-1]);
                    }   //                     前 j 个字符分成 K-1 个串 + [j, i-1] 区间的花费
                }
            }
        }
        return dp[n][k];
    }
};