class Solution {
public:
    int dominantIndex(vector<int>& nums) {
    	int max = -1, secMax = -1, id = 0;
        for(int i = 0; i < nums.size(); ++i)
        {
        	if(nums[i] > max)
        	{
                swap(max,secMax);
        		max = nums[i];
        		id = i;
        	}
        	else if(nums[i] > secMax)
        		secMax = nums[i];
        }
        if(max >= 2*secMax)
        	return id;
        return -1;
    }
};