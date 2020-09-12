class Solution {
public:
    int minimumOperations(string leaves) {
        int n = leaves.size(), i;
        vector<vector<int>> dp(n, vector<int>(3, INT_MAX));
        if(leaves[0]=='r')
            dp[0][0] = 0;
        else
            dp[0][0] = 1;
        if(leaves[1]=='y')
        {
            dp[1][0] = dp[0][0]+1;
            dp[1][1] = dp[0][0];
        }
        else
        {
            dp[1][0] = dp[0][0];
            dp[1][1] = dp[0][0]+1;
        }
        if(leaves[2]=='r')
        {
            dp[2][0] = dp[1][0];
            dp[2][1] = min(dp[1][0]+1, dp[1][1]+1);
            dp[2][2] = dp[1][1];
        }
        else
        {
            dp[2][0] = dp[1][0]+1;
            dp[2][1] = min(dp[1][0], dp[1][1]);
            dp[2][2] = dp[1][1]+1;
        }
        for(i = 3; i < n; i++) 
        {
            if(leaves[i] == 'r')
            {
                dp[i][0] = dp[i-1][0];
                dp[i][1] = min(dp[i-1][0]+1, dp[i-1][1]+1);
                dp[i][2] = min(dp[i-1][1], dp[i-1][2]);
            }
            else
            {
                dp[i][0] = dp[i-1][0]+1;
                dp[i][1] = min(dp[i-1][1],dp[i-1][0]);
                dp[i][2] = min(dp[i-1][1]+1, dp[i-1][2]+1);
            }
        }
        return dp[n-1][2];
    }
};