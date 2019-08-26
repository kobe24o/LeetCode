class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if(matrix.empty())
            return 0;
        int i, j, maxwidth, maxheight, temp = 0, maxarea = 0;
        int r = matrix.size(), c = matrix[0].size();
        pair<int, int> dp[r][c];//以右下角为结束的最大正方形边长
        for(i = 0; i < r; ++i)
            for(j = 0; j < c; ++j)
            {
                dp[i][j].first = 0;//初始化为0
                dp[i][j].second = 0;
            }
        for(i = 0; i < c; ++i)//第一行填表
        {
            if(matrix[0][i] == '1')
            {
                dp[0][i].first = ++temp;
                dp[0][i].second = 1;
            }
            else
                temp = 0;
        }
        temp = 0;
        for(i = 1; i < r; ++i)//第一列填表
        {
            if(matrix[i][0] == '1')
            {   
                dp[i][0].first = 1;
                dp[i][0].second = ++temp;
            }
            else
                temp = 0;
        }
        for(i = 1; i < r; ++i)
            for(j = 1; j < c; ++j)
            {
                if(matrix[i][j] == '1')
                {
                    dp[i][j].first = min(dp[i][j-1].first, dp[i-1][j-1].first)+1;
                    dp[i][j].second = min(dp[i-1][j].second, dp[i-1][j-1].second)+1;
                }
            }

        for(i = 0; i < r; ++i)
            for(j = 0; j < c; ++j)
            {
                if(dp[i][j].first*dp[i][j].second > maxarea)//寻找最大边长
                    maxarea = dp[i][j].first*dp[i][j].second;
            }

        return maxarea;//返回最大面积
    }
};