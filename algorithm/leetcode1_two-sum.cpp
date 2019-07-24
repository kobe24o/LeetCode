class Solution 
{
public:
    vector<int> twoSum(vector<int>& nums, int target) 
    {
        int i,j;
        vector<int> ans;
        for(i = 0; i < nums.size()-1; ++i)
        {
            for(j = i+1; j < nums.size(); ++j)
            {
                if(nums[i]+nums[j] == target)
                {
                    ans.push_back(i);
                    ans.push_back(j);
                    return ans;
                }
            }
        }
        return ans;
    }
};