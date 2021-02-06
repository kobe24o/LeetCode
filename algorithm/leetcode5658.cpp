class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int ans = abs(nums[0]);
        vector<int> presum(nums);
        int n = nums.size();
        for(int i = 1; i < n; i++)
        {
            presum[i] += presum[i-1];
        }
        int MIN = presum[0], MAX = presum[0];
        for(int i = 1; i < n; i++)
        {
            int sum = presum[i];
            ans = max(ans, max(abs(sum), max(abs(sum-MIN), abs(sum-MAX))));
            MIN = min(MIN, sum);
            MAX = max(MAX, sum);
        }
        return ans;
    }
};
