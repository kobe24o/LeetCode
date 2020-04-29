class Solution {
public:
    int minSwap(vector<int>& A, vector<int>& B) {
        int i, n = A.size();
        vector<vector<int>> dp(n,vector<int>(2,INT_MAX));
        dp[0][0] = 0;
        dp[0][1] = 1;
        for(i = 1; i < n; ++i)
        {
            if(A[i]>A[i-1] && B[i]>B[i-1])
            {
                dp[i][0] = min(dp[i][0], dp[i-1][0]);
                dp[i][1] = min(dp[i][1], dp[i-1][1]+1);
            }
            if(A[i]>B[i-1] && B[i]>A[i-1])
            {
                dp[i][0] = min(dp[i][0], dp[i-1][1]);
                dp[i][1] = min(dp[i][1], dp[i-1][0]+1);
            }
        }
        return min(dp[n-1][0], dp[n-1][1]);
    }
};