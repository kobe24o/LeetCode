prim算法：vis标记点，把该点相连的边全部加入优先队列，取出最小的边，边的另一端点的所有边加入队列
```cpp
struct cmp
{
    bool operator()(const pair<int,int>& a, const pair<int,int>& b) const
    {
        return a.second > b.second;//小顶堆, 距离小的优先
    }
};
class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        if(n == 1) return 0;
        vector<bool> vis(n, false);
        vector<vector<pair<int,int>>> edges(n,vector<pair<int,int>>());
        for(int i = 0, j, d; i < n; i++)
        {
            for(j = i+1; j < n; j++)
            {
                
                d = abs(points[i][0]-points[j][0])+abs(points[i][1]-points[j][1]);
                edges[i].push_back({j,d});
                edges[j].push_back({i,d});
            }
        }
        priority_queue<pair<int,int>, vector<pair<int,int>>, cmp> q;
        int to, distance, total = 0, edge_num = 0;
        vis[0] = true;
        for(auto& e : edges[0])
            q.push(e);  
        while(!q.empty())
        {
            to = q.top().first;
            distance = q.top().second;
            q.pop();
            if(!vis[to])
            {
                vis[to] = true;
                total += distance;
                edge_num++;
                if(edge_num == n-1)
                    return total;
                for(auto& e : edges[to])
                    q.push(e);           
            }
        }
        return -1;
    }
};
```
1288 ms 162.2 MB

kruskal 算法：对所有的边排序，短的优先，用并查集检查边的两个端点是否属于一个集合（不属于的话，加入边，合并两个端点）

```cpp
class dsu{
public:
    vector<int> f;
    dsu(int n)
    {
        f.resize(n);
        for (int i = 0; i < n; ++i)
            f[i] = i;
    }
    void merge(int a, int b)
    {
        int fa = find(a), fb = find(b);
        f[fa] = fb;
    }
    int find(int a)
    {
        if(a == f[a])
            return a;
        return f[a] = find(f[a]);
    }
};
struct edge{
    int d;
    int p1, p2;
    edge(int dis, int a, int b)
    {
        d = dis, p1 = a, p2 = b;
    }
};
class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        if(n == 1) return 0;
        dsu u(n);
        vector<edge> e(n*(n-1)/2, edge(0,0,0));
        for(int i = 0, k = 0, j, d; i < n; i++)
        {
            for(j = i+1; j < n; j++)
            {
                d = abs(points[i][0]-points[j][0])+abs(points[i][1]-points[j][1]);
                e[k++] = edge(d,i,j);
            }
        }
        sort(e.begin(), e.end(),[&](auto& a, auto& b){
                return a.d < b.d;
            });
        int N = n-1, p1, p2, d, ans = 0, f1, f2;
        for(int i = 0; i < e.size(); ++i)
        {
            p1 = e[i].p1, p2 = e[i].p2;
            d = e[i].d;
            f1 = u.find(p1), f2 = u.find(p2);
            if(f1 == f2)
                continue;
            ans += d;
            u.f[f1] = f2;
            if(--N == 0)
                break;
        }
        return ans;
    }
};
```
1184 ms 31.6 MB