class Solution {
public:
    int missingElement(vector<int>& nums, int k) {
    	int i = 0, n = nums.size(), ans;
    	for(i = 0; i < n-1; ++i)
    	{
    		if(nums[i+1]-nums[i]-1 < k)
    			k -= nums[i+1]-nums[i]-1;
    		else
    		{
    			ans = nums[i]+k;
    			return ans;
    		}
    	}
    	return nums[n-1]+k;
    }
};