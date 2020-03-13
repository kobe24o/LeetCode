class Solution {
public:
    int backPackII(int m, vector<int> &A, vector<int> &V) {
        int n = A.size(), i, j;
        vector<vector<int>> dp(n,vector<int>(m+1,-1));
        dp[0][0] = 0, dp[0][A[0]] = V[0];
        for(i = 1; i < n; ++i)
        {
            for(j = m; j >= 0; --j)
            {
                if(dp[i-1][j] != -1)//上一行存在的状态
                {
                    dp[i][j] = dp[i-1][j];//不取物品
                    if(j+A[i] <= m)//取物品，且不超重
                        dp[i][j+A[i]] = max(dp[i][j+A[i]],dp[i-1][j]+V[i]);
                }
            }
        }
        return *max_element(dp[n-1].begin(),dp[n-1].end());
        //取最大的方案
    }
};