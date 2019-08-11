class Solution 
{
public:
    int firstMissingPositive(vector<int>& nums) 
    {
        int i, maxNum = INT_MIN;
        for(i = 0; i < nums.size(); ++i)
        {
            if(nums[i] > maxNum)
                maxNum = nums[i];
        }
        for(i = 1; i <= maxNum; ++i)
        {
            if(find(nums.begin(), nums.end(), i) == nums.end())
                return i;
        }
        return i;
    }
};
