class Solution {
public:
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        int i, j, m = nums1.size(), n = nums2.size(), maxDP = INT_MIN;
        vector<vector<int>> dp(m+1, vector<int>(n+1,INT_MIN));
        // dp[i][j] 包含nums1第i个数结尾，nums2第j个数结尾的最大点积
        for(i = 1; i <= m; ++i)
        {
        	for(j = 1; j <= n; ++j)
        	{
        		if(dp[i-1][j-1] > 0)
        			dp[i][j] = max(dp[i-1][j-1]+nums1[i-1]*nums2[j-1] ,max(dp[i-1][j],dp[i][j-1]));
        		else
        			dp[i][j] = max(nums1[i-1]*nums2[j-1] ,max(dp[i-1][j],dp[i][j-1]));
        		maxDP = max(maxDP, dp[i][j]);
        	}
        }
        return maxDP;
    }
};