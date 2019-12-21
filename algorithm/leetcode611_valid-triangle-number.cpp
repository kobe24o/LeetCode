class Solution {
public:
    int triangleNumber(vector<int>& nums) {
    	if(nums.size() < 3)
    		return 0;
        sort(nums.begin(), nums.end());
        int i, j, k, count = 0;
        for(i = nums.size()-1; i >= 2; --i)
        {
        	j = i-1;
        	k = 0;
        	while(k < j)
        	{
        		if(nums[k]+nums[j] <= nums[i])
        		{
        			++k;
        		}
        		else
        		{
        			count += j-k;
        			--j;
        		}
        	}
        }
        return count;
    }
};