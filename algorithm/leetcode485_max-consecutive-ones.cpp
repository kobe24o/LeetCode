class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int count = 0, max = 0, i;
        for(i = 0; i < nums.size(); ++i)
        {
        	if(nums[i])
        		++count;
        	else
        		count = 0;
        	if(count > max)
        		max = count;
        }
        return max;
    }
};