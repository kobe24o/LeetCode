class Solution {
public:
    int connectTwoGroups(vector<vector<int>>& cost) {
        int s1 = cost.size(), s2 = cost[0].size();
        int n = s1+s2;
        // 状态压缩DP，将最多24个状态放在二进制位上表示
        // 最终必须全部是1，表示连接起来了
        vector<int> dp(1<<n, INT_MAX);
        dp[0] = 0;//什么都没有连
        for(int i = 0; i < s1; i++)
        {
            for(int j = 0; j < s2; j++)
            {
                for(int state = (1<<n); state >= 0; state--)
                {
                    if(dp[state] == INT_MAX)
                        continue;
                    dp[state|(1<<(i+s2))|(1<<j)] = min(dp[state|(1<<(i+s2))|(1<<j)], dp[state]+cost[i][j]);
                }
            }
        }
        return dp[1<<n];
    }
};