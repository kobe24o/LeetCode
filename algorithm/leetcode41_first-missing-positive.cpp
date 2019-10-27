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

class Solution 
{
public:
    int firstMissingPositive(vector<int>& nums) 
    {
        int i, n = nums.size();
        for(i = 0; i < nums.size(); ++i)
        {
            while(nums[i]>0 && nums[i] <= n && nums[nums[i]-1] != nums[i])
                swap(nums[i], nums[nums[i]-1]);
        }
        for(i = 0; i < nums.size(); ++i)
        {
            if(nums[i] != i+1)
                return i+1;
        }
        return n+1;
    }
};
