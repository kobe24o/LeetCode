class Solution {
public:
    vector<double> twoSum(int n) {
        vector<vector<int>> dp(n, vector<int>(6*n+1, 0));
        int i, j, k, count = pow(6,n);
        for(j = 1; j <= 6; ++j)
        	dp[0][j] = 1;
        for(i = 1; i < n; ++i)
        {
        	for(j = 6*i; j >= i; --j)
        	{
        		for(k = 6; k >= 1; --k)
        			dp[i][j+k] += dp[i-1][j];
        	}
        }
        vector<double> ans(5*n+1);
        k = 0;
        for(j = n; j <= 6*n; ++j)
            ans[k++] = double(dp[n-1][j])/count;
        return ans;
    }
};

class Solution {
public:
    vector<double> twoSum(int n) {
        vector<int> dp(6*n+1, 0);
        vector<int> temp(6*n+1, 0);
        int i, j, k, count = pow(6,n);
        for(j = 1; j <= 6; ++j)
        	dp[0][j] = 1;
        for(i = 1; i < n; ++i)
        {
        	for(j = 6*i; j >= i; --j)
        	{
        		for(k = 6; k >= 1; --k)
        			temp[j+k] += dp[j];
        	}
        	swap(temp,dp);
        }
        vector<double> ans(5*n+1);
        k = 0;
        for(j = n; j <= 6*n; ++j)
            ans[k++] = double(dp[j])/count;
        return ans;
    }
};