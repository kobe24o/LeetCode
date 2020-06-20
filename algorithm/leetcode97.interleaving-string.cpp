class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        if(s1.size()+s2.size() != s3.size())
        	return false;
        int m = s1.size(), n = s2.size(), i, j, k;
        vector<vector<int>> dp(m+1,vector<int>(n+1,0));
        // dp[i][j] 表示 s1取了i个，s2取了 j 个，可以匹配s3前面的
        dp[0][0] = 1;
        for(i = 0; i < m; i++) 
        	if(s1[i] == s3[i])
        		dp[i+1][0] = 1;
            else
                break;
        for(i = 0; i < n; i++)
        	if(s2[i] == s3[i])
        		dp[0][i+1] = 1;
            else
                break;

        for(i = 1; i <= m; ++i)
        	for(j = 1; j <= n; j++)
        	{	//要求 i，j 状态，该状态下s3是第i+j个字符
        		k = i+j;
        		if(s1[i-1] == s3[k-1])//s1的第i个字符匹配
        			dp[i][j] |= dp[i-1][j];
    			if(s2[j-1] == s3[k-1])//s2的第j个字符匹配
    				dp[i][j] |= dp[i][j-1];
        	}
    	return dp[m][n];
    }
};