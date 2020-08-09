class Solution {
    int ans = 0;
public:
    int minCost(int n, vector<int>& cuts) {
        if(cuts.size() == 1) return n;
        cuts.push_back(0);
        cuts.push_back(n);
        sort(cuts.begin(), cuts.end());
        int m = cuts.size(), i, j;
        vector<vector<int>> dp(m, vector<int>(m, 0x7f7f7f7f));
        for(int i = 1; i < m; ++i)
            dp[i-1][i] = 0;//最小的段不需要切成本为0，最小区间

        for(int len = 2; len < m; ++len)//区间变大
        {
            for(int i = 0; i < m; ++i)//枚举左端点
            {
                int j = i+len;//右端点
                if(j >= m) continue;
                for(int k = j-1; k > i; --k)//从左右端点中间枚举切分点
                {
                    dp[i][j] = min(dp[i][j], dp[i][k]+dp[k][j]+cuts[j]-cuts[i]);
                    //左右两段的成本+切开本次的成本cuts[j]-cuts[i]（总长度）
                }
            }
        }
        return dp[0][m-1];
    }
};