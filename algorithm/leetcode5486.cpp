class Solution {
    int ans = 0;
public:
    int minCost(int n, vector<int>& cuts) {
        if(cuts.size() == 1) return n;
        cuts.push_back(0);
        cuts.push_back(n);
        sort(cuts.begin(), cuts.end());
        int m = cuts.size(), i, j;
        // vector<vector<int>> dp(n+1, vector<int>(m, 0x7f7f7f7f));
        vector<vector<int>> dp(m, vector<int>(m, 0x7f7f7f7f));
        for(int i = 1; i < m; ++i)
            dp[i-1][i] = cuts[i]-cuts[i-1];

        for(int len = 2; len < m; ++len)
        {
            for(int i = 0; i < m; ++i)
            {
                int j = i+len;
                if(j >= m) continue;
                for(int k = j-1; k > i; --k)
                {
                    dp[i][j] = min(dp[i][j], dp[i][k]+dp[k][j]+cuts[j]-cuts[i]);
                }
            }
        }
        return dp[0][m-1]-n;
    }
};