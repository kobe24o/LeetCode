class Solution {
public:
    vector<string> findMissingRanges(vector<int>& nums, int lower, int upper) {
    	int i = 0, n = nums.size();
        long l = lower;
    	vector<string> ans;
    	while(i < n)
    	{
    		if(l > nums[i])
    		{
    			i++;
    			continue;
    		}
    		if(l == nums[i])
    			l++;
    		else if(l < nums[i])
    		{
    			if(l < nums[i]-1)
    				ans.push_back(to_string(l)+"->"+to_string(nums[i]-1));
    			else
    				ans.push_back(to_string(l));
    			l = long(nums[i])+1;
                // [2147483647]
                // 0
                // 2147483647
    		}
    	}
    	if(l < upper)
    		ans.push_back(to_string(l)+"->"+to_string(upper));
    	else if(l==upper)
    		ans.push_back(to_string(l));
    	return ans;
    }
};