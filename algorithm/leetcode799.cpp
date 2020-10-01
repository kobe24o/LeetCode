class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        vector<vector<double>> dp(101, vector<double>(101, 0.0));
        double up_l, up_r;
        dp[0][0] = poured;
        for(int i = 1; i <= query_row; ++i) 
        {
            for(int j = 0; j <= i; ++j)
            {
                up_l = j > 0 ? dp[i-1][j-1] : 0;
                up_r = dp[i-1][j];
                dp[i][j] += up_l > 1 ? (up_l-1)/2.0 : 0;
                dp[i][j] += up_r > 1 ? (up_r-1)/2.0 : 0;
            }
        }
        return min(1.0, dp[query_row][query_glass]);
    }
};