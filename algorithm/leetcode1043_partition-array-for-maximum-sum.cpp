class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& A, int K) {
        int i, n = A.size(), Max = A[0];
        int dp[n] = {0};
        dp[0] = A[0];
        for(i = 1; i < n; ++i)
        {
        	Max = max(Max,A[i]);
        	dp[i] = Max*(i+1);
        }
    }
};