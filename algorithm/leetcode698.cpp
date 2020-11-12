class Solution {
    int target;
    bool ans = false;
    int K;
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        K = k;
        if(sum%k) return false;
        target = sum/k;
        sort(nums.rbegin(), nums.rend());
        if(nums.back() > target)
            return false;
        vector<int> partsum(k, 0);
        dfs(nums, partsum, 0);
        return ans;
    }
    void dfs(vector<int>& nums, vector<int>& partsum, int i)
    {
        if(ans == true) return;
        if(i == nums.size())
        {
            bool flag = true;
            for(int k = 0; k < K; k++)
            {
                if(partsum[k] != target)
                {
                    flag = false;
                    break;
                }
            }
            if(flag)
                ans = true;
            return;
        }
        for(int j = 0; j < K; ++j)
        {
            if(partsum[j]+nums[i] <= target)
            {
                partsum[j] += nums[i];
                dfs(nums, partsum, i+1);
                partsum[j] -= nums[i];
            }
        }
    }
};