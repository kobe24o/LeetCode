class Solution {
public:
    double knightProbability(int N, int K, int r, int c) {
        vector<vector<vector<double>>> dp(N, vector<vector<double>>(N, vector<double>(K+1, 0.0)));
        dp[r][c][K] = 1.0;
        vector<vector<int>> dir = {{2,1},{1,2},{-2,1},{-1,2},{2,-1},{1,-2},{-1,-2},{-2,-1}};
        int i, j, k, x, y, d;
        for(k = K; k > 0; k--) 
        {
            for(i = 0; i < N; i++)
            {
                for(j = 0; j < N; j++)
                {
                    for(d = 0; d < 8; d++)
                    {
                        x = i + dir[d][0];
                        y = j + dir[d][1];
                        if(x>=0 && x<N && y>=0 && y<N)
                        {
                            dp[x][y][k-1] += dp[i][j][k]/8.0;
                        }
                    }
                }
            }
        }
        double ans = 0.0;
        for(i = 0; i < N; i++)
            for(j = 0; j < N; j++)
                ans += dp[i][j][0];
        return ans;
    }
};