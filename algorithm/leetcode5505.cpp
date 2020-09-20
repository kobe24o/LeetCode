class Solution {
public:
    int maxSumRangeQuery(vector<int>& nums, vector<vector<int>>& requests) {
        int n = nums.size();
        vector<long long> f(n+1, 0);
        for(auto& re : requests)
        {
            f[re[0]]++;
            f[re[1]+1]--;
        }
        for(int i = 1; i <= n; i++)
        {
            f[i] += f[i-1];
        }
        f.pop_back();
        sort(f.rbegin(), f.rend());
        sort(nums.rbegin(), nums.rend());
        long long sum = 0, mod = 1e9+7;
        for(int i = 0; i < n; i++)
        {
            sum = (sum+f[i]*nums[i])%mod;
        }
        return sum;
    }
};
