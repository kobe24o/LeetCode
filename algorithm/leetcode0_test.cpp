/**
 * @description: 调试使用
 * @author: michael ming
 * @date: 2019/11/24 22:55
 * @modified by: 
 */
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
    	vector<int> ans(nums.size());
    	int count[9] = {0}, sum = 0, lesscur = 0;
    	for(int i = 0; i < nums.size(); ++i)
    		count[nums[i]]++;
    	for(int i = 0; i < ; ++i)
    	{
    		sum += count[i];
    		count[i] = lesscur;
    		lesscur = sum;
    	}
    	for(int i = 0; i < nums.size(); ++i)
    	{
    		ans[i] = count[nums[i]];
    	}
    	return ans;
    }
};

int main()
{
     Solution s;
     vector<int> nums = {8,1,2,2,3};
     s.smallerNumbersThanCurrent(nums);
     return 0;
}