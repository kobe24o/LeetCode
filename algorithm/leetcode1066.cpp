class Solution {
public:
    int assignBikes(vector<vector<int>>& workers, vector<vector<int>>& bikes) {
        int m = workers.size(), n = bikes.size(), i, j;
        vector<vector<int>> dis(m, vector<int>(n));
        for(i = 0; i < m; ++i)
            for(j = 0; j < n; ++j)
                dis[i][j] = abs(workers[i][0]-bikes[j][0])+ abs(workers[i][1]-bikes[j][1]);
        int M = 1 << m, N = 1 << n;//每个人或者自行车都看成一个二进制位，0还没选，1选了
        vector<vector<int>> dp(M, vector<int>(N, 1000000));
        for(i = 0; i < m; ++i)
            for(j = 0; j < n; ++j)
                dp[1<<i][1<<j] = dis[i][j];
        for(i = 0; i < M; ++i)
            for(j = 0; j < N; ++j)
            {
                int i_ = i, j_ = j;
                m = i&(-i);//二进制数最后一个1代表的数值lowbit
                n = j&(-j);
                while(m > 0)
                {
                    dp[i][j] = min(dp[i][j], dp[i-m][j-n]+dp[m][n]);
                                            //i-m表示少了？个1，少了？个人
                                            //j-n表示少了一辆车
                    i_ -= m;//减掉一个人
                    m = i_&(-i_);
                }
                m = i&(-i);//二进制数最后一个1代表的数值lowbit
                n = j&(-j);
                while(n > 0)
                {
                    dp[i][j] = min(dp[i][j], dp[i-m][j-n]+dp[m][n]);
                                            //i-m表示少了？个1，少了？个人
                                            //j-n表示少了一辆车
                    j_ -= n;//减掉一辆车
                    n = j_&(-j_);
                }
            }
        return *min_element(dp[M-1].begin(), dp[M-1].end());
    }
};