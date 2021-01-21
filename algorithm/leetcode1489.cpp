class dsu{  //并查集
    vector<int> f;
public:
    dsu(int n)
    {
        f.resize(n);
        for(int i = 0; i < n; ++i)
            f[i] = i;
    }
    void merge(int a, int b)
    {
        int fa = find(a), fb = find(b);
        if(fa != fb)
        {
            f[fa] = fb;
        }
    }
    int find(int a)
    {
        if(a == f[a]) return a;
        return f[a] = find(f[a]);
    }
    void reset()
    {
        for(int i = 0; i < f.size(); ++i)
            f[i] = i;
    }
};
class Solution {
public:
    vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>>& edges) {
        vector<int> edgeId(edges.size());
        iota(edgeId.begin(), edgeId.end(), 0);
        sort(edgeId.begin(), edgeId.end(),[&](auto a, auto b){
            return edges[a][2] < edges[b][2];//距离小的优先
        });
        dsu u(n);
        vector<bool> vis(edges.size(), false);
        int mincost = kruskal(vis, u, edgeId, edges, n, 0);
        vector<vector<int>> ans(2);
        for(int i = 0; i < edges.size(); ++i)
        {
            vis[i] = true;//删除这条边
            u.reset();//重置并查集
            int cost = kruskal(vis, u, edgeId, edges, n, 0);
            if(cost > mincost)//删除边以后，cost 变大，或 无法生成树
            {
                ans[0].push_back(i);//关键边
                vis[i] = false;
                continue;
            }
            u.reset();//重置并查集
            u.merge(edges[i][0], edges[i][1]);//不是关键边，且提前把这条边加入树中
            cost = kruskal(vis, u, edgeId, edges, n, edges[i][2]);
            if(cost == mincost)// 权值和 不变，伪关键边
                ans[1].push_back(i);
            vis[i] = false;//恢复这条边
        }
        return ans;
    }
    int kruskal(vector<bool>& vis, dsu& u, vector<int>& edgeId, vector<vector<int>>& edges, int n, int mincost)
    {
        int edge_count = (mincost ? 1 : 0);//提前加入边了吗
        int a, b, id, cost;
        for(int i = 0; i < edgeId.size(); ++i)
        {
            id = edgeId[i];
            if(vis[id]) continue;//边删除了
            a = edges[id][0];
            b = edges[id][1];
            cost = edges[id][2];
            if(u.find(a) != u.find(b))
            {
                u.merge(a, b);
                mincost += cost;
                edge_count++;
            }
            if(edge_count == n-1)
                return mincost;
        }
        return INT_MAX;//无法构造生成树
    }
};