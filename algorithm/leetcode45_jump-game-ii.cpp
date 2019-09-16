class Solution {
public:
    int jump(vector<int>& nums) {
        int steps = 0, i, reach = 0, maxs = 0;
        for(i = 0; i < nums.size()-1; ++i)
        {
        	maxs = max(maxs,nums[i]+i);
        	if(i == reach)
        	{
        		++steps;
        		reach = maxs;
        	}
        }
        return steps;
    }
};