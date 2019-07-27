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
        int maxSum = INT_MIN, n = nums.size();
        maxSubsum(nums,n,0,nums[0],maxSum);
        return maxSum;
    }
    void maxSubsum(vector<int>& nums, int &n, int i0, int curSum, int &maxSum)
    {
        if(i0 == n)
            return;
        if(n == 1)
            maxSum = nums[0];
        for(int i = i0+1; i < n; ++i)
        {
            if(nums[i] >= 0 && curSum >= 0)
            {
                curSum += nums[i];
                if(curSum > maxSum)
                    maxSum = curSum;
            }
            else
            {
                curSum = nums[i];
                if(curSum > maxSum)
                    maxSum = curSum;
                maxSubsum(nums,n,i,nums[i],maxSum);
            }
        }
    }
};

int main()
{
    int arr[2] = {-2,1};
    vector<int> nums(arr,arr+2);
    Solution s;
    cout << s.maxSubArray(nums);
}