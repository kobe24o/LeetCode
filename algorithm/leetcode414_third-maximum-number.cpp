class Solution {
public:
    int thirdMax(vector<int>& nums) {
        int M1, M2, M3;
        M1 = M2 = M3 = INT_MIN;
        for(int i = 0; i < nums.size(); ++i)
        {
        	if(nums[i] > M1)
        		M3 = M2, M2 = M1, M1 = nums[i];
        	else if(nums[i] > M2 && nums[i] < M1)
        		M3 = M2, M2 = nums[i];
        	else if(nums[i] > M3 && nums[i] < M2)
        		M3 = nums[i];
        }
        if(M3 == INT_MIN)
        	return M1;
        return M3;
    }
};