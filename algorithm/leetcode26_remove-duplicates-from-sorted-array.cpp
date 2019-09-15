class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i, dupnums = 0;
        for(i = 1; i < nums.size(); ++i)
        {
        	if(nums[i] == nums[i-1])
        		++dupnums;
        	else
        		nums[i-dupnums] = nums[i];
        }
        return nums.size()-dupnums;
    }
};