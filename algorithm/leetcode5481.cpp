class Solution {
public:
    int minOperations(vector<int>& nums) {
    	int s = 0, maxn = 0;
    	for(int i = 0; i < nums.size(); ++i)
    	{
    		maxn = max(maxn, nums[i]);
    	}
    	for(int i = 0; i < nums.size(); ++i)
    	{
    		if(nums[i] > 0)
    		{
    			while(nums[i])
    			{
    				if(nums[i]&1)//不能整除
    				{
    					s++;//调用
    					nums[i]--;
    				}
    				else
    				{
    					nums[i] /= 2;
    				}
    			}
    		}
    	}
    	while(maxn>1)//大于1时
    	{
    		maxn /= 2;//最大的数能被2除的次数
    		s++;
    	}
    	return s;
    }
};
