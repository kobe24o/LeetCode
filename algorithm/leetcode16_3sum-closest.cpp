class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int i, s, e, minDiffer = INT_MAX, record;
        int cursum = nums[0]+nums[1]+nums[2];
        if(target <= cursum)
        	return cursum;
        for(int i = 0; i < nums.size()-2; ++i)
        {
        	s = i+1;
        	e = nums.size()-1;
        	while(s < e)
        	{
        		cursum = nums[i]+nums[s]+nums[e];
        		if(abs(cursum-target) < minDiffer)
        		{
        			minDiffer = abs(cursum-target);
        			record = cursum;
        		}
        		if(cursum < target)
        			++s;
        		else if(cursum == target)
        			return cursum;
        		else
        			--e;
        	}
        }
        return record;
    }
};