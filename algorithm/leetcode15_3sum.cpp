class Solution 
{
public:
    vector<vector<int>> threeSum(vector<int>& nums) 
    {
    	vector<vector<int>> ans;
    	sort(nums.begin(), nums.end());
    	int n = nums.size(), i;
    	if(n < 3||nums.front()>0||nums.back()<0)
    		return ans;
    	int left, right, templeft, tempright, sum;
    	for(i = 0; i < n-2; ++i)
    	{
    		if(nums[i] > 0)
    			break;
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
    				while(left+1 < right && templeft == nums[++left])
    				{
    					templeft = nums[left];
    				}
    				while(left < right-1 && tempright == nums[--right])
    				{
    					tempright = nums[right];
    				}
    			}
    		}
    	}
    	return ans;
    }
};