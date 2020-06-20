class Solution {
public:
    bool isMatch(string s, string p) {
        int m = s.size(), n = p.size(), i, j;
        vector<vector<int>> dp(m+1, vector<int>(n+1, false));
        dp[0][0] = true;
        for(i = 0; i <= m; ++i)
        {
            for(j = 1; j <= n; ++j)
            {
                if(p[j-1] == '*')//p第j个字符为*
                {
                    dp[i][j] |= dp[i][j-2];//*匹配0次前面的字符
                    if(match(s,p,i,j-1))
                    //s第i个和p的第j-1个可以匹配, *匹配再多匹配一次i-1
                        dp[i][j] |= dp[i-1][j];
                }
                else//p第j个字符不为*
                {
                    if(match(s,p,i,j))//必须是i、j能够匹配
                        dp[i][j] |= dp[i-1][j-1];
                }
            }
        }
        return dp[m][n];
    }
    bool match(string &s, string &p, int i, int j) 
    {   //第i,j个字符能匹配
        return i>0 && (p[j-1]=='.' || p[j-1]==s[i-1]);
    }
};

class Solution {
public:
    bool isMatch(string s, string p) {
        if(p.empty())
            return s.empty();
        if(p[1]=='*')
        {
            return isMatch(s, p.substr(2)) || 
              ((!s.empty() && (s[0]==p[0] || p[0]=='.')) && isMatch(s.substr(1),p));
        }
        else
            return (!s.empty() && (s[0]==p[0]||p[0]=='.')) && isMatch(s.substr(1),p.substr(1));
    }
};
