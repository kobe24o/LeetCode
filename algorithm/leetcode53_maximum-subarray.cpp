/**
 * @description: 
 * @author: michael ming
 * @date: 2019/7/27 9:07
 * @modified by: 
 */
#include <vector>
#include <iostream>
#include <memory.h>

using namespace std;
class Solution
{
public:
    int maxSubArray(vector<int>& nums)
    {
        int maxSumOfArr = INT_MIN, maxsum = 0;
        for(int i = 0; i < nums.size(); ++i)
        {
            maxsum = max(nums[i],maxsum+nums[i]);
            maxSumOfArr = max(maxSumOfArr, maxsum);
        }
        return maxSumOfArr;
    }
};

int main()
{
    int arr[9] = {-2,1,-3,4,-1,2,1,-5,4};
    vector<int> nums(arr,arr+9);
    Solution s;
    cout << s.maxSubArray(nums);
}