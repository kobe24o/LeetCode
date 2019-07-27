/**
 * @description: 
 * @author: michael ming
 * @date: 2019/7/27 9:07
 * @modified by: 
 */
#include <vector>
#include <iostream>

using namespace std;
class Solution
{
public:
    int maxSubArray(vector<int>& nums)
    {
        int i, n = nums.size();
        int states[n];
        states[0] = nums[0];
        for(i = 1; i < nums.size(); ++i)
        {
            if(states[i-1] + nums[i] >= states[i-1])
            {
                if(states[i-1]+nums[i] > nums[i])
                    states[i] = states[i-1]+nums[i];
                else
                    states[i] = nums[i];
            }
            else
                states[i] = nums[i];
        }
        int maxlen = 0;
        for(i = 0; i < nums.size(); ++i)
        {
            if(states[i] > maxlen)
                maxlen = states[i];
        }
        return maxlen;
    }
};

int main()
{
    int arr[9] = {-2,1,-3,4,-1,2,1,-5,4};
    vector<int> nums(arr,arr+9);
    Solution s;
    cout << s.maxSubArray(nums);
}