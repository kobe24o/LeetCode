class Solution {
public:
    int mctFromLeafValues(vector<int>& arr) {
        int n = arr.size();
        vector<vector<pair<int, int>>> dp(n, vector<pair<int, int>>(n, {INT_MAX, 0}));
        //dp[i][j] 表示区间 [i,j] 的 {非叶节点的min(sum), 区间的最大叶子节点值}
        for(int i = 0; i < n; i++) //初始化
        {
            dp[i][i].first = 0;//sum
            dp[i][i].second = arr[i];//maxval
        }
        for(int len = 1; len < n; ++len)//区间长度
        {
            for(int i = 0, j; i+len < n; ++i)//左端点
            {
                j = i+len;//右端点
                for(int k = i; k < j; ++k)//枚举中间端点
                {
                    if(dp[i][j].first > dp[i][k].first+dp[k+1][j].first+dp[i][k].second*dp[k+1][j].second)
                    {                   //左区间的和 + 右区间的和 + 当前节点的val = maxL*maxR
                        dp[i][j].first = dp[i][k].first+dp[k+1][j].first+dp[i][k].second*dp[k+1][j].second;
                                        //用更小的sum更新
                        dp[i][j].second = max(dp[i][k].second, dp[k+1][j].second);
                                        // 更新区间的最大叶节点值
                    }
                }
            }
        }
        return dp[0][n-1].first;
    }
};