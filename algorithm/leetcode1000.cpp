class Solution {
public:
    int mergeStones(vector<int>& stones, int K) {
    	int n = stones.size();
    	if((n-1)%(K-1) != 0) return -1;
    	vector<vector<int>> dp(n+1, vector<int>(n+1, 0));
    	vector<int> sum(n+1, 0);
    	for(int i = 1; i <= n; i++)
    		sum[i] = stones[i-1] + sum[i-1];//前缀和
    	for(int len = 1; len <= n; len++)
    	{	//区间长度
    		for(int i = 1; i+len <= n; i++)
    		{	//左端点
    			int j = i+len;
                dp[i][j] = INT_MAX;
    			for(int mid = i; mid < j; mid += K-1)//枚举中间分割点
    			{   //注意mid不能++, 而是 + K-1 然后区间不能合并，dp初始为0，得出的结果小
    				dp[i][j] = min(dp[i][j], dp[i][mid]+dp[mid+1][j]);
    			}
    			if(len%(K-1) == 0)//如果区间能够合并，加上区间重量
    				dp[i][j] += sum[j]-sum[i-1];
    		}
    	}
    	return dp[1][n];
    }
};