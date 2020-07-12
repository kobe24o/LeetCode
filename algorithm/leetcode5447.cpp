class Solution {
public:
    bool winnerSquareGame(int n) {
        vector<bool> dp(n+1, false);
        int i, j;
        for(i = 0; i <= n; ++i)//遍历石子的样本维度
        {
            for(j = 1; j*j+i <= n; ++j)
            {	//拿走 j^2 个石子
                if(!dp[i])//如果只有 i 个石头的时候输
                    dp[j*j+i] = true;//那么有j*j+i个石头时，就赢了
            }
        }
        return dp[n];
    }
};
