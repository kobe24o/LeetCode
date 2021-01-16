class dsu // 并查集
{
    int top;
    vector<int> f;
public:
    vector<int> count;//某节点对应集团的总节点个数
    dsu(int n)
    {
        f.resize(n);
        count.resize(n);
        for(int i = 0 ;i < n; ++i)
            f[i] = i, count[i] = 1;
    }
    int find(int a)
    {
        if(a == f[a])
            return a;
        return f[a] = find(f[a]);
    }
    void merge(int a, int b)
    {
        int fa = find(a), fb = find(b);
        if(fa != fb)
        {
            f[fa] = fb;
            count[fb] += count[fa];
        }
    }
};
class Solution {
public:
    vector<int> hitBricks(vector<vector<int>>& grid, vector<vector<int>>& hits) {
        int m = grid.size(), n = grid[0].size(), len = hits.size();
        vector<int> ans(len, 0);
        vector<vector<int>> copy(grid);
        for(auto& h : hits)
            copy[h[0]][h[1]] = 0;//先敲掉
        dsu u(m*n+1);
        int top = m*n;
        vector<vector<int>> dir = {{-1,0},{0,-1},{1,0},{0,1}};
        for(int j = 0; j < n; ++j)
            if(copy[0][j]==1)
                u.merge(j, top);
        for(int i = 1; i < m; ++i)
        {
            for(int j = 0; j < n; ++j)
            {
                if(copy[i][j]==1)
                {
                    for(int k = 0; k < 4; ++k)
                    {
                        int x = i + dir[k][0];
                        int y = j + dir[k][1];
                        if(x>=0 && x < m && y>=0 && y<n && copy[x][y]==1)
                        {
                            u.merge(x*n+y, i*n+j);
                        }
                    }
                }
            }
        }
        for(int i = len-1; i >= 0; --i)
        {
            int x0 = hits[i][0], y0 = hits[i][1];
            if(grid[x0][y0]==0)
                continue;//原来就是空的，敲了不起作用
            int ct1 = u.count[u.find(top)];// 注意要先find top 的 father
            for(int k = 0; k < 4; ++k)
            {
                int x = x0 + dir[k][0];
                int y = y0 + dir[k][1];
                if(x>=0 && x < m && y>=0 && y<n && copy[x][y]==1)
                {
                    u.merge(x*n+y, x0*n+y0);
                }
            }
            if(x0 == 0)
                u.merge(y0, top);
            ans[i] = max(0, u.count[u.find(top)]-ct1-1);
            copy[x0][y0]=1;
        }
        return ans;
    }
};