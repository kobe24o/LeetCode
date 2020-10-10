#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    int tallestBillboard(vector<int>& rods) {
        if(rods.size() <= 1)
            return 0;
        int dp[20][5001], n = rods.size();
        int total = accumulate(rods.begin(), rods.end(), 0);
        // dp[i][j] 表示处理完 i 支架，两边差距为 j 时，可以组成的最大高度
        memset(dp, -1, sizeof(dp));
        dp[0][rods[0]] = dp[0][0] = 0;
        for(int i = 1; i < rods.size(); i++)
        {   //样本维度
            for(int j = 0; j <= total; ++j)
            {
                if(dp[i-1][j] == -1)
                    continue;
                dp[i][j] = dp[i-1][j];
                dp[i][j+rods[i]] = dp[i-1][j];
                // if(j != rods[i])
                dp[i][abs(j-rods[i])] = max(dp[i][abs(j-rods[i])], dp[i-1][j]+min(j, rods[i]));
                // else
                //  dp[i][0] = max(dp[i][0], dp[i-1][j]+j)
            }
        }
        return dp[n-1][0]==-1 ? 0 : dp[n-1][0];
    }
};
int main()
{
     Solution s;
    vector<int> r = {1,2,3,4,5,6}, c = {4,7};
    vector<string> n = {"a","a","a","a","a","b","b","b","b","b","b"};
    vector<string> t = {"23:20","11:09","23:30","23:02","15:28","22:57","23:40","03:43","21:55","20:38","00:19"};

    vector<vector<int>> g = {{0,1},{0,2},{2,3},{2,4},{2,5}};
    s.tallestBillboard(r);
    return 0;
}