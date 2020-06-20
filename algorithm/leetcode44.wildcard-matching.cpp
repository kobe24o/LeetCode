class Solution {
public:
    bool isMatch(string s, string p) {
        int m = s.size(), n = p.size(), i, j, k;
        vector<vector<int>> dp(m+1, vector<int>(n+1,0));
        dp[0][0] = true;
        for(i = 0; i <= m; ++i)
        {
            for(j = 1; j <= n; ++j)
            {
                if(p[j-1]=='*')
                {
                	dp[i][j] |= dp[i][j-1] | (i>0 ? dp[i-1][j] : false);
                    //            *匹配0个    *匹配多个（后面多加一个i）
                }
                else
                {
                	if(match(s,p,i,j))
                		dp[i][j] |= dp[i-1][j-1];
                }
            }
        }
        return dp[m][n];
    }
    bool match(string& s, string& p, int i, int j)
    {
    	return i>0 && (s[i-1]==p[j-1] || p[j-1]=='?');
    }
};