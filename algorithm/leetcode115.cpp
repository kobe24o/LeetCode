class Solution {
public:
    int numDistinct(string s, string t) {
        if(t=="") return 1;
        if(s.size() < t.size()) return 0;
        int m = s.size(), n = t.size(), i, j;
        vector<<vector<int>> dp(m+1, vector<int>(n+1,0));
        dp[0][0] = 1;
        for(i = 1; i <= m; i++)
        {
        	for(j = 1; j <= n; j++)
        	{
        		if(s[i-1]==t[j-1])
        			dp[i][j] = dp[i-1][j-1]+dp[i-1][j];
        		else
        			dp[i][j] = dp[i-1][j-1];
        	}
        }
        return dp[m][n];
    }
};