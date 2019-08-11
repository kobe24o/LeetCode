/**
 * @description:
 * @author: michael ming
 * @date: 2019/8/11 23:26
 * @modified by:
 */
class Solution
{
public:
    int majorityElement(vector<int>& nums)
    {
        unordered_map<int, int> maps1;
        for(int i = 0; i < nums.size(); ++i)
        {
            if(maps1.find(nums[i]) == maps1.end())
                maps1[nums[i]] = 1;
            else
                maps1[nums[i]]++;
            if(maps1[nums[i]] > nums.size()/2)
                return nums[i];
        }
    }
};