/**
 * @description: 调试使用
 * @author: michael ming
 * @date: 2019/11/24 22:55
 * @modified by: 
 */
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        int n = jobDifficulty.size(), i, j, k, MAX = 0;
        if(n < d)
            return -1;
        vector<vector<int>> dp(d,vector<int>(n, INT_MAX));
        for(i = 0; i <= n-d; ++i)
        {
            MAX = max(MAX, jobDifficulty[i]);
            dp[0][i] = MAX;
        }
        for(i = 1; i < d; ++i)
        {
            for(j = i; j <= n-d+i; ++j)
            {
                MAX = 0;
                for(k = j; k <= n-d+i; ++k)
                {
                    MAX = max(MAX, jobDifficulty[k]);
                    dp[i][k] = min(dp[i][k], MAX+dp[i-1][j-1]);
                }

            }
        }
        int MIN = INT_MAX;
        for(i = 0; i < n; ++i)
        {
            if(dp[d-1][i] < MIN)
                MIN = dp[d-1][i];
        }

        for(i = 0; i < d; ++i)
        {
            for(j = 0; j < n; ++j)
                cout << dp[i][j] << " ";
            cout << endl;
        }
        return MIN;


    }
};

int main()
{
    Solution s;
    vector<int> m =
            {11,111,22,222,33,333,44,444};
    s.minDifficulty(m,6);

}