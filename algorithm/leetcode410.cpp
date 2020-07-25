class Solution {
public:
    int splitArray(vector<int>& nums, int m) {
    	long long l = 0, r = 1e15, maxsum, ans;
    	while(l <= r)
    	{
    		maxsum = l+((r-l)>>1);
    		if(canSplitM(nums, maxsum, m))
    			r = maxsum-1, ans = maxsum;
    		else
    			l = maxsum+1;
    	}
    	return ans;
    }
    bool canSplitM(vector<int>& nums, long long maxsum, int m) 
    {
    	int count = 0;
    	long long sum = 0;
    	for(int i = 0; i < nums.size(); ++i)
    	{
    		if(sum+nums[i] <= maxsum)
    			sum += nums[i];
    		else
    		{
    			count++;
    			sum = 0;
    			i--;
    		}
    		if(count >= m)
    			return false;
    	}
    	return true;
    }
};