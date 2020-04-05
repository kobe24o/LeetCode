class Solution {
public:
    int maxSatisfaction(vector<int>& satisfaction) {
        sort(satisfaction.rbegin(), satisfaction.rend());
        int sum = 0, ans = 0;
        for(int i = 0; i < satisfaction.size(); ++i)
        {
        	sum += satisfaction[i];
        	if(sum <= 0)
        		break;
        	ans += sum;
        }
        return ans;
    }
};

class Solution {
public:
    int maxSatisfaction(vector<int>& satisfaction) {
        sort(satisfaction.begin(), satisfaction.end());
        int i, j, n = satisfaction.size();
        vector<vector<int>> dp(n+1, vector<int>(n+1,0));
        //dp[i][j] 表示前i道菜，做j道的最大满意度
        dp[1][0] = 0, dp[1][1] = satisfaction[0];
        for(i = 2; i <= n; ++i)
        {
        	for(j = 1; j <= i; ++j)
        	{
        		if(j == i)
        			dp[i][j] = dp[i-1][j-1]+j*satisfaction[i-1];
        		else
        			dp[i][j] = max(dp[i-1][j], dp[i-1][j-1]+j*satisfaction[i-1]);
        	}
        }
        int ans = INT_MIN;
        for(i = 0; i <= n; ++i)
        	ans = max(ans, dp[n][i]);
        return ans;
    }
};