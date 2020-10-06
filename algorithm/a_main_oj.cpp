#include <bits/stdc++.h>

using namespace std;


class Solution {
    vector<int> ans, son, dp;
    vector<vector<int>> g;
public:
    vector<int> sumOfDistancesInTree(int N, vector<vector<int>>& edges) {
        ans.resize(N);
        son.resize(N);
        dp.resize(N);
        g.resize(N);
        for(auto& e : edges)
        {
            g[e[0]].push_back(e[1]);
            g[e[1]].push_back(e[0]);
        }
        dfs1(0, -1);
        dfs2(0, -1);
        return ans;
    }
    void dfs1(int u, int f)
    {
        son[u] = 1;
        dp[u] = 0;
        for(auto v : g[u])
        {
            if(v == f)
                continue;
            dfs1(v, u);
            dp[u] += dp[v]+son[v];
            son[u] += son[v];
        }
    }
    void dfs2(int u, int f)
    {
        ans[u] = dp[u];
        for(auto v : g[u])
        {
            if(v == f)
                continue;
            int dpu = dp[u], dpv = dp[v];
            int sonu = son[u], sonv = son[v];
            dp[u] -= dp[v]+son[v];
            son[u] -= son[v];
            dp[v] += dp[u]+son[u];
            son[v] += son[u];
            dfs2(v, u);
            dp[u] = dpu, dp[v] = dpv;
            son[u] = sonu, son[v] = sonv;
        }
    }
};
int main()
{
     Solution s;
    vector<int> r = {3,8}, c = {4,7};
    vector<string> n = {"a","a","a","a","a","b","b","b","b","b","b"};
    vector<string> t = {"23:20","11:09","23:30","23:02","15:28","22:57","23:40","03:43","21:55","20:38","00:19"};

    vector<vector<int>> g = {{0,1},{0,2},{2,3},{2,4},{2,5}};
    s.sumOfDistancesInTree(6,g);
    return 0;
}