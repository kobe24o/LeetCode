class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
    	if(nums.size() == 0)
    		return 0;
        int i = 0, j = 0, len = INT_MAX, sum = nums[0];
        while(j < nums.size())
        {
        	if(sum < s)
        	{
        		j++;
        		if(j < nums.size())
        		sum += nums[j];
        	}
        	else if(sum >= s)
        	{
        		if(j-i+1 < len)
        			len = j-i+1;
        		sum -= nums[i];
        		i++;
        	}
        }
        if(len == INT_MAX)
        	return 0;
        return len;
    }
};