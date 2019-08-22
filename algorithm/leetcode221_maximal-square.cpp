class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if(matrix.empty())
            return 0;
        int i, j, maxEdgeLen = 0;
        int r = matrix.size(), c = matrix[0].size();
        int dp[r][c];//以右下角为结束的最大正方形边长
        memset(dp,0,sizeof(int)*r*c);
        for(i = 0; i < r; ++i)//第一行填表
        {
            if(matrix[0][i] == '1')
                dp[0][i] = 1;
        }
        for(i = 1; i < c; ++i)//第一列填表
        {
            if(matrix[i][0] == '1')
                dp[i][0] = 1;
        }
        for(i = 1; i < r; ++i)
            for(j = 1; j < c; ++j)
            {
                if(matrix[i][j] == '0')
                    dp[i][j] = 0;
                else//matrix[i][j] == '1'
                {
                    if(matrix[i-1][j] == '1' && matrix[i][j-1] == '1')
                        dp[i][j] = dp[i-1][j-1]+1;
                    else
                        dp[i][j] = 1;
                }
            }

        for(i = 0; i < r; ++i)
            for(j = 0; j < c; ++j)
            {
                if(dp[i][j] > maxEdgeLen)
                    maxEdgeLen = dp[i][j];
            }

        return maxEdgeLen*maxEdgeLen;
    }
};