class Solution {
public:
    int minDistance(string w1, string w2) {
        int m = w1.size(), n = w2.size(), i, j;
        if(m==0 || n==0)
        	return max(m,n);
        vector<vector<int>> dp(m,vector<int>(n,0));
        //填写第一行第一列
        for(j = 0; j < n; ++j)
        {
        	if(w1[0] == w2[j])	dp[0][j] = j;
        	else if(j != 0)	 	dp[0][j] = 1+dp[0][j-1];
        	else	 			dp[0][j] = 1;
        }
        for(i = 0; i < m; ++i)
        {
        	if(w1[i] == w2[0])	dp[i][0] = i;
        	else if(i != 0)	 	dp[i][0] = 1+dp[i-1][0];
        	else	 			dp[i][0] = 1;
        }
        //填写状态表
        for(i = 1; i < m; ++i)
        {
        	for(j = 1; j < n; ++j)
        	{
        		if(w1[i] == w2[j])
        			dp[i][j] =   min(dp[i-1][j-1], min(1+dp[i-1][j],1+dp[i][j-1]));
        		else
        			dp[i][j] = min(1+dp[i-1][j-1], min(1+dp[i-1][j],1+dp[i][j-1]));
        	}
        }
        return dp[m-1][n-1];
    }
}; 