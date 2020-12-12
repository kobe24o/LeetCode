class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        int n = nums.size();
        vector<int> sum(1+n, 0), ans(n);
        for(int i = 1; i <= n; ++i) 
        {
            sum[i] = nums[i-1]+sum[i-1];
        }
        
        for(int i = 1; i <= n; ++i)
        {
            int presum = sum[i-1];
            int tailsum = sum[n]-sum[i];
            ans[i-1] = (i-1)*nums[i-1]-presum+tailsum-(n-i)*nums[i-1];
        }
        return ans;
    }
};