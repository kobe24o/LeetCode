class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int i;
        long maxSum = LONG_MIN, curSum = 0;
        for(i = 0; i < k; ++i)
        	curSum += nums[i];
        maxSum = curSum;
        while(i < nums.size())
        {
        	curSum += -nums[i-k]+nums[i];
        	maxSum = max(maxSum, curSum);
        	i++;
        }
        return (double)maxSum/k;
    }
};