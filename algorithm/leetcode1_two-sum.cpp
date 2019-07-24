//暴力查找
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

//哈希法
class Solution 
{
public:
    vector<int> twoSum(vector<int>& nums, int target) 
    {
        int i, d;
        vector<int> ans;
        unordered_map<int,int> unomap;//unordered_map是哈希表
        for(i = 0; i < nums.size(); ++i)//建立哈希表
            unomap[nums[i]] = i;//哈希数组下标是值，存的原来的下标
        for(i = 0; i < nums.size(); ++i)
        {
            d = target - nums[i];
            if(unomap.find(d) != unomap.end() && unomap[d]>i)
            {//如果查找到了，且不是同一个元素
                ans.push_back(i);
                ans.push_back(unomap[d]);
                break;
            }
        }
        return ans;
    }
};