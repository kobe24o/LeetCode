class Solution {
public:
    int countEval(string s, int result) {
        if(s=="")
            return 0;
        int i, j, n = s.size(), len;
        vector<vector<int>> dp0(n,vector<int>(n,0));
        vector<vector<int>> dp1(n,vector<int>(n,0));
        //dp？[i][j] 表示 区间[i,j]内运算值为 ？ 的方案数
        for(i = 0; i < n; i+=2)
        {
            if(s[i]=='1')
                dp1[i][i] = 1;
            else
                dp0[i][i] = 1;
        }
        for(len = 2; len <= n-1; len += 2)
        {
            for(i = 0; i < n-len; i += 2)
            {
                for(j = i; j <= i+len-2; j+=2)
                {
                    if(s[j+1]=='&')
                    {
                        dp1[i][i+len] += dp1[i][j]*dp1[j+2][i+len];
                        dp0[i][i+len] += dp0[i][j]*dp0[j+2][i+len]+dp1[i][j]*dp0[j+2][i+len]+dp0[i][j]*dp1[j+2][i+len];
                    }
                    else if(s[j+1]=='|')
                    {
                        dp1[i][i+len] += dp1[i][j]*dp1[j+2][i+len]+dp1[i][j]*dp0[j+2][i+len]+dp0[i][j]*dp1[j+2][i+len];
                        dp0[i][i+len] += dp0[i][j]*dp0[j+2][i+len];
                    }
                    else//^
                    {
                        dp1[i][i+len] += dp1[i][j]*dp0[j+2][i+len]+dp0[i][j]*dp1[j+2][i+len];
                        dp0[i][i+len] += dp0[i][j]*dp0[j+2][i+len]+dp1[i][j]*dp1[j+2][i+len];
                    }
                }
            }
        }
        if(result)
            return dp1[0][n-1];
        return dp0[0][n-1];
    }
};