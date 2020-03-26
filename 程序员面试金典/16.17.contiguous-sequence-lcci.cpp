class Solution {
public:
    int maxSubArray(vector<int>& nums) {
    	vector<int> dp(nums);
    	for(int i = 1; i < nums.size(); ++i)
    	{
    		if(dp[i-1] > 0)
    			dp[i] = max(dp[i], nums[i]+dp[i-1]);
    	}
    	return *max_element(dp.begin(),dp.end());
    }
};

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
    	int maxSum = nums[0], dp_i_1 = nums[0], dp_i;
    	for(int i = 1; i < nums.size(); ++i)
    	{
			dp_i = max(nums[i], nums[i]+dp_i_1);
			maxSum = max(maxSum, dp_i);
			dp_i_1 = dp_i;
    	}
    	return maxSum;
    }
};

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
    	return divide(nums,0,nums.size()-1);
    }

    int divide(vector<int>& nums, int l, int r)
    {
    	if(l == r)
    		return nums[l];
    	int i, mid = l+((r-l)>>1);
    	int Lsum = divide(nums,l,mid);
    	int Rsum = divide(nums,mid+1,r);
    	int Ls = 0, Rs = 0, maxL = INT_MIN, maxR = INT_MIN;
    	for(i = l; i <= mid; ++i)
    	{
    		Ls += nums[i];
    		maxL = max(maxL, Ls);
    	}
    	for(i = mid+1; i <= r; ++i)
    	{
    		Rs += nums[i];
    		maxR = max(maxR, Rs);
    	}
    	return max(maxL+maxR, max(Lsum,Rsum));
    }
};