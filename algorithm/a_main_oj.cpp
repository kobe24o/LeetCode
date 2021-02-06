#include <bits/stdc++.h>

using namespace std;
void print2Dvector(vector<vector<int>>& a)
{
    int m = a.size(), n = a[0].size();
    for(int i = 0; i < m; ++i)
    {
        for(int j = 0; j < n; ++j)
            cout << a[i][j] << " ";
        cout << endl;
    }
}

class Solution {
public:
    int maxValue(vector<vector<int>>& events, int k) {
        sort(events.begin(), events.end(),[&](auto a, auto b){
            if(a[1] == b[1])
                return a[0] < b[0];
            return a[1] < b[1];
        });
        int n = events.size();
        typedef pair<int, int> pii;
        vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(k+1, vector<int>(2,-1)));
        dp[0][0] = {0, 0};
        for(int i = 1; i <= n; i++)
            dp[i][1] = {events[i-1][1], events[i-1][2]};
        for(int i = 1; i <= n; i++)
        {
            for(int K = 0; K <= k; K++)
            {
                int lastend = dp[i-1][K][0];
                int lastV = dp[i-1][K][1];
                if(lastend == -1)
                    continue;
                if(lastV > dp[i][K][1])
                    dp[i][K] = {lastend, lastV};
                else if(lastV == dp[i][K][1] && lastend < dp[i][K][0])
                    dp[i][K][0] = lastend;
                if(K+1 <= k && lastend < events[i-1][0])
                {
                    if(dp[i][K+1][1] < lastV+events[i-1][2])
                        dp[i][K+1] = {events[i-1][1], lastV+events[i-1][2]};
                    else if(dp[i][K+1][1] == lastV+events[i-1][2] && lastend < dp[i][K+1][0])
                        dp[i][K+1][0] = lastend;
                }
            }
        }
        int ans = 0;
        for(int K = 0; K <= k; K++)
            ans = max(ans, dp[n][K][1]);
        return ans;
    }
};


int main()
{

    Solution s;
    vector<vector<int>> g = {{1,2,4},{3,4,3},{2,3,10}};
    vector<int> a = {-3,-5,-3,-2,-6,3,10,-10,-8,-3,0,10,3,-5,8,7,-9,-9,5,-8};
    string str = "A man, a plan, a canal: Panama";
    string s1 = "rgeat", s2 = "great";
    cout << s.maxValue(g,2) << endl;

//    cout << bool(true^false) << endl;
    return 0;
}