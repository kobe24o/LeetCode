class Solution {
public:
    int minCut(string s) {
    	int i,j,len,n = s.size();
    	vector<int> dp(n,0);
        vector<vector<bool>> ispalind(n,vector<bool>(n,false));
    	if(s.size()<=1)
    		return 0;
    	for(i = 0; i < n; ++i)
        {
        	dp[i] = i;
        	ispalind[i][i] = true;
        	if(i < n-1 && s[i]==s[i+1])
                ispalind[i][i+1] = true;
        }
        for(len = 1; len < n; ++len)
        {
            for(i = 0; i < n-len; ++i)
            {
                if(ispalind[i][i+len-1] && i-1>=0 && s[i-1]==s[i+len])//是回文串
                    ispalind[i-1][i+len] = true;
            }
        }
    	for(i = 1; i < n; ++i)
    	{
    		for(j = i; j > 0; --j)
    		{
                if(ispalind[0][i])
                    dp[i] = 0;
    			else if(ispalind[j][i])
    				dp[i] = min(dp[i], dp[j-1]+1);
    		}
    	}
    	return dp[n-1];
    }
};