class Solution {
public:
    bool oneEditAway(string a, string b) {
        int m = a.size(), n = b.size(), i, j;
        if(abs(m-n) >= 2)
            return false;
        if(m==0 || n==0)
            return true;
        vector<vector<int>> dp(m,vector<int>(n,0));
        //初始化第一行，第一列的编辑距离
        for(j = 0; j < n; j++)
        {
            if(a[0]==b[j])	dp[0][j] = j;
            else if(j != 0) dp[0][j] = 1+dp[0][j-1];
            else 			dp[0][j] = 1;
        }
        for(i = 0; i < m; i++)
        {
            if(a[i]==b[0])	dp[i][0] = i;
            else if(i != 0) dp[i][0] = 1+dp[i-1][0];
            else 			dp[i][0] = 1;
        }
        //填写状态表
        for(i = 1; i < m; ++i)
        {
            for(j = 1; j < n; ++j)
            {
                if(a[i] == b[j])
                    dp[i][j] =   min(dp[i-1][j-1],dp[i-1][j]+1,dp[i][j-1]+1);
                else
                    dp[i][j] = min(1+dp[i-1][j-1],dp[i-1][j]+1,dp[i][j-1]+1);
            }
        }
        return (dp[m-1][n-1] < 2);
    }

    int min(int x, int y, int z)
    {
        int m = INT_MAX;
        if(x < m)	m = x;
        if(y < m)	m = y;
        if(z < m)	m = z;
        return m;
    }
};