class Solution {
public:
    int minimumDistance(string s) {
        vector<vector<int>> pos(27, vector<int>(2));
        int count = 1;
        for(int i = 0; i < 5 && count < 27; ++i)
            for(int j = 0; j < 6 && count < 27; ++j)
            {
                pos[count++] = {i, j};
            }
        int n = s.size(), mindis = INT_MAX;
        int dp[301][27][27];
        memset(dp, 0x7f, sizeof(dp));
        dp[0][s[0]-'A'+1][0] = 0;
        for(int i = 1; i < n; ++i)
        {
            int c = s[i]-'A'+1;
            for(int c1 = 1; c1 <= 26; ++c1)
            {
                for(int c2 = 0; c2 <= 26; ++c2)
                {
                    if(dp[i-1][c1][c2] == 0x7f7f7f7f)
                        continue;
                    // 字母c由第1个手指输入
                    dp[i][c][c2] = min(dp[i][c][c2], dp[i-1][c1][c2]+abs(pos[c][0]-pos[c1][0])+abs(pos[c][1]-pos[c1][1]));
                    // 字母c由第2个手指输入
                    if(c2 == 0)//第二个手指还没输入
                        dp[i][c1][c] = min(dp[i][c1][c], dp[i-1][c1][c2]);
                    else
                        dp[i][c1][c] = min(dp[i][c1][c], dp[i-1][c1][c2]+abs(pos[c][0]-pos[c2][0])+abs(pos[c][1]-pos[c2][1]));
                }
            }
        }
        for(int c1 = 1; c1 <= 26; ++c1)
            for(int c2 = 0; c2 <= 26; ++c2)
                mindis = min(mindis, dp[n-1][c1][c2]);
        return mindis;
    }
};