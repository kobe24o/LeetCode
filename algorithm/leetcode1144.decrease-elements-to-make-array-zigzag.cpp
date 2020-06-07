class Solution {
public:
    int movesToMakeZigzag(vector<int>& nums) {
    	int i = 1, n = nums.size(), op1 = 0, op2 = 0;
    	int cur;
    	for(i = 0; i < n; i++) 
    	{
    		cur = nums[i];
    		//目标: 都小于两侧
    		if(i&1)//奇数
    		{
	    		if(cur >= nums[i-1])
	    		{
	    			op1 += cur-nums[i-1]+1;
	    			cur = nums[i-1]-1;
	    		}
	    		if(i+1 < n && cur >= nums[i+1])
	    		{
	    			op1 += cur-nums[i+1]+1;
	    		}
    		}
    		else
    		{
	    		if(i > 0 && cur >= nums[i-1])
	    		{
	    			op2 += cur-nums[i-1]+1;
	    			cur = nums[i-1]-1;
	    		}
	    		if(i+1 < n && cur >= nums[i+1])
	    		{
	    			op2 += cur-nums[i+1]+1;
	    		}
    		}
    	}
    	return min(op1, op2);
    }
};