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

struct cmp{
    bool operator()(char a, char b) const
    {
        return a > b;
    }
};
// Solution
class Solution {
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n = startTime.size();
        vector<int> id(n);
        iota(id.begin(), id.end(), 0);
        sort(id.begin(), id.end(),[&](auto a, auto b){
            return endTime[a] < endTime[b];
        });
        map<int,int> dp;
        dp[0] = 0;
        dp[endTime[id[0]]] = profit[id[0]];
        int ans = profit[id[0]];
        for(int i = 1; i < n; i++)
        {
            int idx = id[i];
            auto it = dp.upper_bound(startTime[idx]);
            int dp_prev = (--it)->second;
            dp[endTime[idx]] = max(dp[endTime[idx]], dp_prev+profit[idx]);
            ans = max(ans, dp[endTime[idx]]);
        }

        return ans;
    }
};

int main()
{

    Solution s;
    vector<int> a = {4,2,4,8,2}, b = {5,5,5,10,8}, c={1,2,8,10,4};
    string s1 = "D450";
    cout << s.jobScheduling(a,b,c) << endl;


    return 0;
}