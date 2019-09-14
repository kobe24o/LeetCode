class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int i, occurred = 0;
        for(i = 0; i < nums.size(); ++i)
        {
        	if(nums[i] != val)
        		nums[i-occurred] = nums[i];
        	else
        		++occurred;
        }
        return nums.size()-occurred;
    }
};