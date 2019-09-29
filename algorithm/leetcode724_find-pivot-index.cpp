class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int i = 0, j = nums.size()-1, sum = 0, cursum  = 0;
        for(i = 0; i < nums.size(); ++i)
        	sum += nums[i];
        for(i = 0; i < nums.size(); ++i)
        {
        	if(2*cursum == sum-nums[i])
        		return i;
        	else
        		cursum += nums[i];
        }
        return -1;
    }
};