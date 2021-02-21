class Solution {
public:
    int maximumScore(vector<int>& nums, vector<int>& multipliers) {
        int n = nums.size(), m = multipliers.size();
        typedef long long LL;
        vector<vector<LL>> dp(m+1, vector<LL>(m+2, INT_MIN));
        dp[0][1] = 0;
        for(int len = 1; len <= m; len++)//乘了多少数字了
        {
            for(int i = 1; i <= len; i++)//剩余数字区间的左端点
            {
                int j = n+i-len-1;//左端是 i 时，乘以len次，右端要乘的下标
                dp[len][i+1] = max(dp[len][i+1], dp[len-1][i]+1LL*multipliers[len-1]*nums[i-1]);
                dp[len][i] = max(dp[len][i], dp[len-1][i]+1LL*multipliers[len-1]*nums[j]);
            }
        }
        LL ans = INT_MIN;
        for(int i = 1; i <= m+1; i++)
            ans = max(ans, dp[m][i]);
        return ans;
    }
};
