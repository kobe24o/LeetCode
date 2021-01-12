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
    vector<int> sortItems(int n, int m, vector<int>& group, vector<vector<int>>& beforeItems) {
        for(int i = 0; i < n; i++)
        {
            if(group[i] == -1)
                group[i] = m++;
        }
        vector<vector<int>> itemgraph(n);
        vector<vector<int>> groupgraph(m);
        vector<int> itemIndegree(n, 0);
        vector<int> groupIndegree(m, 0);
        for(int i = 0; i < n; i++)
        {
            for(auto j : beforeItems[i])
            {
                itemgraph[j].push_back(i);
                itemIndegree[i]++;
                groupgraph[group[j]].push_back(group[i]);
                groupIndegree[group[i]]++;
            }
        }
        vector<vector<int>> g_items(m);
        queue<int> q;
        for(int i = 0; i < n; i++)
            if(itemIndegree[i] == 0)
                q.push(i);
        int countItem = 0;
        while(!q.empty())
        {
            int i = q.front();
            q.pop();
            countItem++;
            g_items[group[i]].push_back(i);
            for(auto j : itemgraph[i])
            {
                if(--itemIndegree[j]==0)
                    q.push(j);
            }
        }
        if(countItem != n)
            return {};
        vector<int> g_order;
        for(int i = 0; i < m; i++)
            if(groupIndegree[i] == 0)
                q.push(i);
        while(!q.empty())
        {
            int g = q.front();
            q.pop();
            g_order.push_back(g);
            for(auto j : groupgraph[g])
            {
                if(--groupIndegree[j]==0)
                    q.push(j);
            }
        }
        if(!q.empty())
            return {};
        vector<int> ans(n);
        int idx = 0;
        for(auto g : g_order)
        {
            for(auto i : g_items[g])
                ans[idx++] = i;
        }
        return ans;
    }
};


int main()
{

    Solution s;
    vector<vector<int>> g = {{},{6},{5},{6},{3,6},{},{},{}};
    vector<int> a = {-1,-1,1,0,0,1,0,-1}, b = {15,15,15,15,15}, c={1,2,8,10,4};
    string str = "cdbcbbaaabab";
    s.sortItems(8,2,a,g);
//    cout << s.sortItems(8,2,a,g) << endl;


    return 0;
}