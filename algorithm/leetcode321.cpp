class Solution {
public:
    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
    	int m = nums1.size(), n = nums2.size();
    	vector<vector<vector<string>>> dp(k+1, vector<vector<string>>(m+1, vector<string>(n+1, "#")));
    	dp[0][0][0] = "/";
        string str;
    	for(int t = 1; t <= k; t++) 
    	{
    		for(int i = 0; i <= m; i++)
    		{                
    			for(int j = 0; j <= n; j++)
    			{
    				if(dp[t-1][i][j] == "#")
    					continue;
                    
    				if(i < m)
    				{
                        str = to_string(nums1[i]);
    					dp[t][i+1][j] = max(dp[t][i+1][j], dp[t-1][i][j]+str);
                        dp[t-1][i+1][j] = max(dp[t-1][i+1][j], dp[t-1][i][j]);
                        // cout << dp[t][i+1][j] << endl;
    				}                    
    				if(j < n)
    				{
                        str = to_string(nums2[j]);
    					dp[t][i][j+1] = max(dp[t][i][j+1], dp[t-1][i][j]+str);
                        dp[t-1][i][j+1] = max(dp[t-1][i][j+1], dp[t-1][i][j]);
                        // cout << dp[t][i][j+1] << endl;
    				}
    			}
    		}
    	}
    	vector<int> ans(k, 0);
    	string res = "";
        for(int i = 0; i <= m; ++i)
        {
            for(int j = 0; j <= n; ++j)
                res = max(res, dp[k][i][j]);
        }
    	for(int i = 0; i < k; ++i)
            ans[i] = res[i+1]-'0';
    	return ans;
    }
};