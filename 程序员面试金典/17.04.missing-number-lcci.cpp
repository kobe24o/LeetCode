class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int i, sum = 0, n = nums.size();
        for(i = 0; i < nums.size(); ++i)
        	sum += nums[i];
        return n*(n+1)/2-sum;
    }
};

class Solution {
public:
    int missingNumber(vector<int>& nums) {
    	int XOR = 0;
    	for(int i = 0; i < nums.size(); ++i)
    		XOR ^= i^nums[i];
    	XOR ^= nums.size();
    	// 0,1,...n,nums[0],...nums[n-1]
    	// 出现两次的异或抵消为0，出现一次的就是答案
    	return XOR;
    }
};