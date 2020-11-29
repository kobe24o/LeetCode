class Solution {
public:
    int minimumMountainRemovals(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp1(n, 1), dp2(n, 1);
        for(int i = 1; i < n; ++i)
        {
            for(int j = i-1; j >= 0; --j)
            {
                if(nums[j] < nums[i])
                    dp1[i] = max(dp1[i], dp1[j]+1);
            }
        }
        for(int i = n-2; i >= 0; --i)
        {
            for(int j = i+1; j < n; ++j)
            {
                if(nums[j] < nums[i])
                    dp2[i] = max(dp2[i], dp2[j]+1);
            }
        }
        int ans = INT_MAX;
        for(int i = 1; i < n-1; ++i)
        {
            ans = min(ans, n-(dp1[i]+dp2[i]-1));
        }
        return ans;
    }
};