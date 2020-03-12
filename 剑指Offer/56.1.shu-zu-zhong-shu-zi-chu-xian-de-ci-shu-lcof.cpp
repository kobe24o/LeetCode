class Solution {
public:
    vector<int> singleNumbers(vector<int>& nums) {
    	int i, XOR = 0;
    	for(i = 0; i < nums.size(); ++i)
    		XOR ^= nums[i];

    	for(i = 0; i < 32; ++i)
    	{
    		if(XOR & (1<<i))
    			break;
    	}
    	int a = 0, b = 0;
    	for(auto& n : nums)
    	{
    		if(n&(1<<i))
    			a ^= n;
    		else
    			b ^= n;
    	}
    	return {a, b};
    }
};