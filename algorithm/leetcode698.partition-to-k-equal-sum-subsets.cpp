class Solution {
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
    	if(nums.size() < k)
    		return false;
    	int sum = 0, i, j;
    	for(i = 0 ; i < nums.size(); ++i)
    		sum += nums[i];
    	if(sum%k != 0)	return false;//数不可分
    	//dp求解，每个元素拿或者不拿，求解所有的状态
        sum >>= 1;
    	vector<bool> state(sum+1, false);
    	state[0] = true;//初始化
    	state[nums[0]] = true;
    	for(i = 1; i < nums.size(); ++i)
    	{
    		for(j = sum; j >= 0; --j)
    		{	
                if(state[j] && j+nums[i] <= sum)
    			    state[j+nums[i]] = true;
    		}
    		if(state[sum])
    			return true;
    	}
    	return false;
    }
};