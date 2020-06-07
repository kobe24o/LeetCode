class Solution {
public:
    int movesToMakeZigzag(vector<int>& nums) {
    	int i = 1, n = nums.size(), op1 = 0, op2 = 0;
    	int cur1;
    	for(i = 0; i < n; i++) 
    	{
    		//目标: 都小于两侧
    		if(i&1)//奇数
    		{
    			cur1 = nums[i];
	    		if(cur1 >= nums[i-1])
	    		{
	    			op1 += cur1-nums[i-1]+1;
	    			cur1 = nums[i-1]-1;
	    		}
	    		if(i+1 < n && cur1 >= nums[i+1])
	    		{
	    			op1 += cur1-nums[i+1]+1;
	    		}
    		}
    		else
    		{
    			cur1 = nums[i];
	    		if(n > 0 && cur1 >= nums[i-1])
	    		{
	    			op2 += cur1-nums[i-1]+1;
	    			cur1 = nums[i-1]-1;
	    		}
	    		if(i+1 < n && cur1 >= nums[i+1])
	    		{
	    			op2 += cur1-nums[i+1]+1;
	    		}
    		}
    	}
    	return min(op1, op2);
    }
};