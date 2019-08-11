#include <vector>
#include <algorithm>
using namespace std;
class Solution
{
public:
    vector<vector<int>> threeSum(vector<int>& nums) 
    {
    	vector<vector<int>> ans;
    	sort(nums.begin(), nums.end());//排序
    	int n = nums.size();
    	if(n < 3||nums.front()>0||nums.back()<0)
    		return ans;
    	int left, right, templeft, tempright, sum;
    	for(int i = 0; i < n-2; ++i)
    	{
    		if(nums[i] > 0)//全为正，找不到解了
    			break;
    		if(i > 0 && nums[i-1] == nums[i])//相同元素，跳过
                continue;
    		left = i+1, right = n-1;
    		while(left < right)
    		{
    			sum = nums[i]+nums[left]+nums[right];
    			if(sum > 0)
    				right--;
    			else if(sum < 0)
    				left++;
    			else
    			{
    				ans.push_back(vector<int> {nums[i], nums[left], nums[right]});
    				templeft = nums[left];
    				tempright = nums[right];
    				while(left < right && templeft == nums[++left])
    				{
                        //跳过相同元素
    				}
    				while(left < right && tempright == nums[--right])
    				{
                        //跳过相同元素
    				}
    			}
    		}
    	}
    	return ans;
    }
};
int main()
{
    int nums[] = {-1, 0, 1, 2, -1, -4};
    vector<int> vec(nums,nums+6);
    Solution s;
    s.threeSum(vec);
    return 0;
}