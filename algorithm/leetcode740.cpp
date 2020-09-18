class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
    	if(nums.empty())
    		return 0;
    	map<int,int> num_points;
    	for(int num : nums)
    		num_points[num] += num;//数字和其对应的分数
    	vector<pair<int,int>> num_pts(num_points.begin(), num_points.end());//map key有序
    	vector<vector<int>> dp(num_points.size(), vector<int>(2, 0));
    	// dp[i][0] 表示不拿， dp[i][1] 表示拿 i 号数字的最大得分
    	dp[0][1] = num_pts[0].second;//拿第一个数的得分
    	int maxpoints = dp[0][1];
    	for(int i = 1; i < num_pts.size(); ++i)
    	{
    		if(num_pts[i-1].first+1 < num_pts[i].first)//数字间隔大于1
    			dp[i][1] = num_pts[i].second + max(dp[i-1][0], dp[i-1][1]);
    								//前一个数可以拿或者不拿
    		else // num_pts[i-1].first+1 == num_pts[i].first 间隔1
            	//我要拿了，前一个不能拿
    			dp[i][1] = num_pts[i].second + dp[i-1][0];
                
    		dp[i][0] = max(dp[i-1][0], dp[i-1][1]);	
    		//我不拿，那么前一个拿或者不拿
    		maxpoints = max(maxpoints, max(dp[i][0], dp[i][1]));
    	}
    	return maxpoints;
    }
};