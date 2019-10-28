class Solution {
public:
    int thirdMax(vector<int>& nums) {
        long M1, M2, M3;
        M1 = M2 = M3 = LONG_MIN;
        for(int i = 0; i < nums.size(); ++i)
        {
        	if(nums[i] > M1)
        		M3 = M2, M2 = M1, M1 = nums[i];
        	else if(nums[i] > M2 && nums[i] < M1)
        		M3 = M2, M2 = nums[i];
        	else if(nums[i] > M3 && nums[i] < M2)
        		M3 = nums[i];
        }
        if(M3 == LONG_MIN)
        	return M1;
        return M3;
    }
};