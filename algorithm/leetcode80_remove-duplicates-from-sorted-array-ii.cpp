class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size() < 3)
        	return nums.size();
        int end = 1;
        for(int i = 2; i< nums.size(); ++i)
        {
        	if(nums[i] != nums[end-1])
        	{
        		end++;
        		nums[end] = nums[i];
        	}
        }
        return end+1;
    }
};