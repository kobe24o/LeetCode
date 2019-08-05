class Solution 
{
public:
    int findLengthOfLCIS(vector<int>& nums) 
    {
        if(nums.size() == 0)
            return 0;
    	int len = 1, ans = 1;
        for(int i = 1; i < nums.size(); ++i)
        {
        	if(nums[i] > nums[i-1])
    		{
    			len++;
    		}
    		else
    		{
    			len = 1;
    		}
    		if(len > ans)
    			ans = len;
        }
        return ans;
    }
};