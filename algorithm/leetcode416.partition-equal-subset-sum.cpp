class Solution {
public:
    bool canPartition(vector<int>& nums) {
    	if(nums.size() <= 1)
    		return false;
    	int sum = 0, i, j;
    	for(i = 0 ; i < nums.size(); ++i)
    		sum += nums[i];
    	if(sum&1)	return false;//奇数不可分
    	//dp求解，每个元素拿或者不拿，求解所有的状态
    	set<int> state;
    	state.insert(0);//初始化
    	state.insert(nums[0]);
    	for(i = 1; i < nums.size(); ++i)
    	{
    		for(auto it = state.rbegin(); it != state.rend(); ++it)
    		{	//用set，不能用哈希set，且必须逆序遍历，新插入的不会被本次遍历到
    			state.insert(*it+nums[i]);
    		}
    		if(state.count(sum>>1))
    			return true;
    	}
    	return false;
    }
};

class Solution {
public:
    bool canPartition(vector<int>& nums) {
    	if(nums.size() <= 1)
    		return false;
    	int sum = 0, i, j;
    	for(i = 0 ; i < nums.size(); ++i)
    		sum += nums[i];
    	if(sum&1)	return false;//奇数不可分
    	//dp求解，每个元素拿或者不拿，求解所有的状态
    	vector<bool> state(sum+1, false);
    	state[0] = true;//初始化
    	state[nums[0]] = true;
    	for(i = 1; i < nums.size(); ++i)
    	{
    		for(j = sum; j >= 0; --j)
    		{	
                if(state[j])
    			    state[j+nums[i]] = true;
    		}
    		if(state[sum>>1])
    			return true;
    	}
    	return false;
    }
};
class Solution {
public:
    bool canPartition(vector<int>& nums) {
    	if(nums.size() <= 1)
    		return false;
    	int sum = 0, i, j;
    	for(i = 0 ; i < nums.size(); ++i)
    		sum += nums[i];
    	if(sum&1)	return false;//奇数不可分
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