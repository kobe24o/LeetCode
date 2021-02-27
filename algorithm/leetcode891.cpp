class Solution {
public:
    int sumSubseqWidths(vector<int> &A) {
        long long ans = 0, mod = 1e9+7;
        long long n = A.size();
        sort(A.begin(), A.end());
        // 每个数作为最小值的时候，右侧有多少种方案 2^(n-i-1);
        // 每个数作为最大值的时候，左侧有多少种方案 2^(i);
        vector<long long> p2(n);
        p2[0] = 1;
        for(int i = 1; i < n; i++)
            p2[i] = (p2[i-1]<<1)%mod;
        for(int i = 0; i < n; ++i)
        {
            ans = (ans + (p2[i]-p2[n-i-1])*A[i])%mod;
        }
        return ans;
    }
};