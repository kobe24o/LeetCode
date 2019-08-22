#include<vector>
#include<cstring>
#include<iostream>
using namespace std;
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if(matrix.empty())
            return 0;
        int i, j, n, incr, maxEdgeLen = 0;
        int r = matrix.size(), c = matrix[0].size();
        int dp[r][c];//以右下角为结束的最大正方形边长
        for(i = 0; i < r; ++i)
            for(j = 0; j < c; ++j)
            {
                dp[i][j] = 0;//初始化为0
            }
        for(i = 0; i < c; ++i)//第一行填表
        {
            if(matrix[0][i] == '1')
                dp[0][i] = 1;
        }
        for(i = 1; i < r; ++i)//第一列填表
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
                    n = dp[i-1][j-1];
                    incr = 0;
                    while(n--)
                    {
                        incr++;//记录同时为1的次数
                        if(matrix[i-incr][j] == '1' && matrix[i][j-incr] == '1')
                        {
                            continue;//往左和往上同时判断都为1吗？
                        }
                        else//有中断则跳出
                        {
                            incr--;
                            break;
                        }
                    }
                    dp[i][j] = 1+incr;
                }
            }

        for(i = 0; i < r; ++i)
            for(j = 0; j < c; ++j)
            {
                if(dp[i][j] > maxEdgeLen)//寻找最大边长
                    maxEdgeLen = dp[i][j];
            }

        return maxEdgeLen*maxEdgeLen;//返回最大面积
    }
};
int main()
{
    vector<vector<char>> matrix = {{'1','0','1','0','0'},{'1','0','1','1','1'},{'1','1','1','1','1'},{'1','0','0','1','0'}};
    Solution s;
    cout << s.maximalSquare(matrix) << endl;
    return 0;
}