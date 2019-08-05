class Solution 
{
public:
    int lengthOfLIS(vector<int>& nums) 
    {
        int n = nums.size();
        if(n == 0)
            return 0;
        int maxlen[n], ans;
        int i, j;
        for(i = 0; i < n; ++i)
            maxlen[i] = 1;//至少为1，自己
        for(i = 1; i < n; ++i)
        {
        	ans = 1;
            for(j = 0; j < i; ++j)
            {
            	if(nums[i] > nums[j] && maxlen[j]+1 > ans)
            	{
            		ans = maxlen[j]+1;
            		maxlen[i] = ans;
            	} 
        	}
        }
        for(ans = 1, i = 0; i < n; ++i)
        {
        	if(maxlen[i] > ans)//取最大值
        		ans = maxlen[i];
        }
        return ans;
    }
};
