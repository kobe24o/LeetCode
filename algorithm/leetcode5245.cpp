class Solution {
public:
    int maxHeight(vector<vector<int>>& cub) {
        vector<vector<int>> C(6, vector<int>(3));
        C[0] = {0,1,2};
        C[1] = {0,2,1};
        C[2] = {1,0,2};
        C[3] = {1,2,0};
        C[4] = {2,0,1};
        C[5] = {2,1,0};//最后一维是高度维
        for(auto& c : cub)
            sort(c.begin(), c.end());
        sort(cub.begin(), cub.end());
        int n = cub.size();
        vector<vector<int>> dp(n, vector<int>(6, 0));
        dp[0][0] = cub[0][C[0][2]];
        dp[0][1] = cub[0][C[1][2]];
        dp[0][2] = cub[0][C[2][2]];
        dp[0][3] = cub[0][C[3][2]];
        dp[0][4] = cub[0][C[4][2]];
        dp[0][5] = cub[0][C[5][2]];
        
        for(int i = 1; i < n; ++i)
        {
            for(int c1 = 0; c1 < 6; ++c1)
            {
                dp[i][c1] = cub[i][C[c1][2]];//初始化为自己的高度
                for(int j = 0; j < i; ++j)
                {
                    for(int c2 = 0; c2 < 6; ++c2)
                    {   
                        if(cub[j][C[c2][0]] <= cub[i][C[c1][0]]
                            && cub[j][C[c2][1]] <= cub[i][C[c1][1]]
                            && cub[j][C[c2][2]] <= cub[i][C[c1][2]])
                        {
                            dp[i][c1] = max(dp[i][c1], dp[j][c2]+cub[i][C[c1][2]]);
                        }
                    }
                }
            }
        }
        int ans = 0;
        for(int i = 0; i < n; i++)
        {
            for(int k = 0; k < 6; k++)
            {
                ans = max(ans, dp[i][k]);
            }
        }
        return ans;
    }
};