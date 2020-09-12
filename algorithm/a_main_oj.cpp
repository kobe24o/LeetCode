#include<iostream>
#include<vector>
#include<unordered_set>
#include<random>
#include<set>
#include<algorithm>
using namespace std;
#include <string>     // std::string, std::stoi
#include <map>
#include<stack>
# include<queue>
#include<iostream>
#include<string>
using namespace std;

class Solution {
public:
    int chaseGame(vector<vector<int>>& edges, int startA, int startB) {
        int n = edges.size();
        startA--;
        startB--;
        vector<int> degree(n, 0);
        vector<vector<int>> g(n);
        int d2 = 0;
        for(auto& e : edges)
        {
            g[e[0]-1].push_back(e[1]-1);
            g[e[1]-1].push_back(e[0]-1);
            degree[e[0]-1]++;
            degree[e[1]-1]++;
            if(degree[e[0]-1]==2)
                d2++;
            if(degree[e[1]-1]==2)
                d2++;
        }
        bool near = (find(g[startA].begin(), g[startA].end(), startB) != g[startA].end());
        if(d2 == n && !near)
            return -1;
        if(near)
            return 1;
        queue<int> q;
        vector<bool> vis(n, false);
        for(int i = 0; i < n; i++)
        {
            if(degree[i] == 1)
            {
                q.push(i);
            }
        }
        int l1 = 0, cur, d1 = 0, inpos;
        d2 = 0;
        bool occurinline = false;
        while(!q.empty())
        {
            cur = q.front();
            inpos = cur;
            q.pop();
            degree[cur]--;

            for(int nt : g[cur])
            {
                if(--degree[nt] == 1)
                {
                    q.push(nt);
                }
            }
            if(cur == startB)
            {
                occurinline = true;
                d1 = l1;
            }
            l1++;
        }
        if(!occurinline)
            return -1;
        d2 = l1-d1;
        int T, d3 = 0;

        for(int nt : g[inpos])
            if(degree[nt]==2)
                T = nt;

        queue<int> q1;
        q1.push(startA);
        vis[startA] = true;
        bool flag = false;
        while(!q1.empty())
        {
            int size = q1.size();
            while(size--)
            {
                cur = q1.front();
                q1.pop();
                if(cur == T){
                    flag = true;
                    break;
                }
                for(int nt : g[cur])
                {
                    if(!vis[nt])
                    {
                        vis[nt] = true;
                        q1.push(nt);
                    }
                }
            }
            if(flag)
                break;
            d3++;
        }
        if(d3 > d2)
            return -1;
        return d3+l1;
    }
};

int main()
{
    vector<int> l = {2,1};
    vector<vector<int>> t = {{1,2},{2,3},{3,4},{4,1},{2,5},{5,6}};
    vector<vector<int>> t1 = {{14,7,11},{11,14,5},{14,3,10}};
    Solution s;
    string str = "bacbdab";
    cout << s.chaseGame(t,3,5) <<endl;
    //读出二进制文件中的内容并输出到显示器6

    return 0;
}


