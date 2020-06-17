class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        if(nums.empty()) return {};
    	sort(nums.begin(), nums.end());
    	int i, j, n = nums.size();
    	int maxlen = 1, maxlenid = 0;
    	vector<pair<int,int>> dp(n);
    	for(i = 0; i < n; ++i)
    		dp[i] = make_pair(1, -1);
    	for(i = 1; i < n; ++i)
    	{
    		for(j = i-1; j >= 0; --j)
    		{
    			if(nums[i]%nums[j] == 0 && dp[j].first+1 > dp[i].first)
    			{
    				dp[i].first = dp[j].first + 1;
    				dp[i].second = j;//前一个数
    			}
    		}
    		if(dp[i].first > maxlen)
    		{
    			maxlen = dp[i].first;
    			maxlenid = i;
    		}
    	}
    	vector<int> ans(maxlen);
    	ans[maxlen-1] = nums[maxlenid];
    	for(i = maxlen-2; i >= 0; --i)
    	{
    		ans[i] = nums[dp[maxlenid].second];
    		maxlenid = dp[maxlenid].second;
    	}
    	return ans;
    }
};