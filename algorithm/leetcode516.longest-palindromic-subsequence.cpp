class Solution {
public:
    int longestPalindromeSubseq(string s) {
    	int i, j, n = s.size();
    	vector<vector<int>> dp(n,vector<int>(n,0));
        for(i = 0; i < n; ++i)
            dp[i][i] = 1;
    	for(j = 0; j < n; ++j)
    	{
    		for(i = j-1; i >= 0; --i)//区间从小往大，所以逆序
    		{
    			if(s[i] == s[j])
    				dp[i][j] = dp[i+1][j-1]+2;
    			else
    				dp[i][j] = max(dp[i+1][j], dp[i][j-1]);
    		}
    	}
    	return dp[0][n-1];
    }
};