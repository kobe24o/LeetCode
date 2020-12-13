class Solution {
public:
    int stoneGameVII(vector<int>& stones) {
        int n = stones.size();
        vector<int> sum(n+1);
        for(int i = 1; i <= n; ++i)
            sum[i] = sum[i-1] + stones[i-1];//前缀和
        vector<vector<int>> dp(n+1, vector<int>(n+1, 0));
        for(int i = 1; i+1 <= n; ++i)
        {   // 初始化情况，区间只剩2颗石头的情况下，先手拿的最大分差
            dp[i][i+1] = max(stones[i-1], stones[i]);
        }
        for(int len = 2; len <= n; ++len)
        {   // 区间长度
            for(int i = 1; i+len <= n; ++i)
            {   // 左端点
                int j = i+len; // 右端点
                dp[i][j] = max(dp[i][j], 
                                max(-dp[i+1][j]+sum[j]-sum[i],-dp[i][j-1]+sum[j-1]-sum[i-1]));
                            // 上一个人的分差取负，就是我的分差 + 我这次获得的分数（前缀和获取）
            }
        }
        return dp[1][n];
    }
};