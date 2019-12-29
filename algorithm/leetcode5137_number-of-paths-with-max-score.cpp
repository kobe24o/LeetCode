class Solution {
    int n, i, j;
public:
    vector<int> pathsWithMaxScore(vector<string>& board) {
        n = board.size();
        board[0][0] = board[n-1][n-1] = '0';//方便后面处理起点和终点的得分
        vector<vector<pair<int,int>>> dp(n,vector<pair<int,int>> (n, make_pair(0,0)));
        dp[n-1][n-1].second = 1;//起点的方案数为1
        for(i = n-2; i >= 0 && board[i][n-1] != 'X'; --i)
        {	//初始化最后1列
            dp[i][n-1].first = dp[i+1][n-1].first+board[i][n-1]-'0';//得分累加
            dp[i][n-1].second = 1;//方案数只有1种
        }
        for(i = n-2; i >= 0 && board[n-1][i] != 'X'; --i)
        {	//初始化最后1行
            dp[n-1][i].first = dp[n-1][i+1].first+board[n-1][i]-'0';
            dp[n-1][i].second = 1;
        }
        
        for(i = n-2; i >= 0; i--)
        {
            for(j = n-2; j >= 0; j--)
            {	//填写其他dp数组
                if(board[i][j] != 'X')//没有障碍
                {
                    if(dp[i+1][j+1].second)//右下角 如果有方案数，则可以过来
                    {
                        if(dp[i+1][j+1].first+board[i][j]-'0' > dp[i][j].first)//得分大，更新得分，方案数
                        {
                            dp[i][j].first = dp[i+1][j+1].first+board[i][j]-'0';
                            dp[i][j].second = dp[i+1][j+1].second%1000000007;
                        }
                        else if(dp[i+1][j+1].first+board[i][j]-'0' == dp[i][j].first)//得分相等，方案数相加
                        {
                            dp[i][j].second += dp[i+1][j+1].second%1000000007;
                        }
                    }
                    if(dp[i][j+1].second)//右边
                    {
                        if(dp[i][j+1].first+board[i][j]-'0' > dp[i][j].first)
                        {
                            dp[i][j].first = dp[i][j+1].first+board[i][j]-'0';
                            dp[i][j].second = dp[i][j+1].second%1000000007;
                        }
                        else if(dp[i][j+1].first+board[i][j]-'0' == dp[i][j].first)
                        {
                            dp[i][j].second += dp[i][j+1].second%1000000007;
                        }
                    }
                    if(dp[i+1][j].second)//下边
                    {
                        if(dp[i+1][j].first+board[i][j]-'0' > dp[i][j].first)
                        {
                            dp[i][j].first = dp[i+1][j].first+board[i][j]-'0';
                            dp[i][j].second = dp[i+1][j].second%1000000007;
                        }
                        else if(dp[i+1][j].first+board[i][j]-'0' == dp[i][j].first)
                        {
                            dp[i][j].second += dp[i+1][j].second%1000000007;
                        }
                    }
                }
            }
        }
        return {dp[0][0].first, dp[0][0].second%1000000007};//得分，方案数
    }
};