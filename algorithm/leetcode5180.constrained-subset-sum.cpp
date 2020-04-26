class Solution {
public:
    int constrainedSubsetSum(vector<int>& nums, int k) {
        int i, n = nums.size(), maxsum = INT_MIN;
        vector<int> dp(n, 0);
        dp[0] = nums[0];
        maxsum = nums[0];
        deque<int> q;
        q.push_back(0);
        for(i = 1; i < n; i++) 
        {
        	if(i-q.front() > k)//距离超过k了
        		q.pop_front();
        	if(dp[q.front()] > 0)
        	{
        		dp[i] = dp[q.front()]+nums[i];
        		maxsum = max(maxsum,dp[i]);
        	}
            else
                dp[i] = nums[i];
        	while(!q.empty() && dp[i] >= dp[q.back()])
        		q.pop_back();
        	q.push_back(i);
        }
        return maxsum;
    }
};