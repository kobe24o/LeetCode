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

class node
{
public:
    int push, bi, bj, pi, pj;
    node(int n, int a, int b, int c, int d)
    {
        push = n;
        bi = a;
        bj = b;
        pi = c;
        pj = d;
    }
};
struct hashf
{
    unsigned long long operator()(node v) const
    {
        return 1ULL*v.bi*pow(21,3)+v.bj*pow(21,2)+v.pi*21+v.pj;
    }
};
struct eqf
{
    bool operator()(node v1, node v2) const//不能写引用
    {
        return v1.push==v2.push && v1.bi==v2.bi && v1.bj==v2.bj
               && v1.pi==v2.pi && v1.pj==v2.pj;
    }
};
struct cmp
{
    bool operator()(node& a, node& b) const
    {
        return a.push > b.push;//推得次数少的优先
    }
};
class Solution {
    vector<vector<int>> dir = {{1,0},{0,1},{0,-1},{-1,0}};
public:
    int minPushBox(vector<vector<char>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int targetx, targety, boxi, boxj, peoplei, peoplej, push = 0, size;
        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(grid[i][j] == 'S')
                    peoplei = i, peoplej = j;
                else if(grid[i][j] == 'B')
                    boxi = i, boxj = j;
                else if(grid[i][j] == 'T')
                    targetx = i, targety = j;
            }
        }
        priority_queue<node, vector<node>, cmp> q;
        node state(0, boxi, boxj, peoplei, peoplej);
        q.push(state);
        unordered_set<node, hashf, eqf> vis;
        vis.insert(state);
        while(!q.empty())
        {
            int pj = q.top().pj;
            int pi = q.top().pi;
            int bj = q.top().bj;
            int bi = q.top().bi;
            push = q.top().push;
            if(bi==targetx && bj==targety)
                return push;
            q.pop();
            int nextbi, nextbj, nextpi, nextpj, pushPosx, pushPosy;
            for(int d = 0; d < 4; d++)
            {
                nextbi = bi+dir[d][0];
                nextbj = bj+dir[d][1];
                if(nextbi<0 || nextbi>=m || nextbj<0 || nextbj>=n || grid[nextbi][nextbj] == '#')
                    continue; // 箱子下一个位置不合法
                nextpi = bi;
                nextpj = bj;
                pushPosx = bi-dir[d][0];//人推动箱子前的位置
                pushPosy = bj-dir[d][1];
                if(pushPosx<0 || pushPosx>=m || pushPosy<0 || pushPosy>=n || grid[pushPosx][pushPosy] == '#')
                    continue; // 推箱子位置不合法
                vector<vector<bool>> record(m, vector<bool>(n, false));
                if(!canReachPushPos(grid,pi,pj,bi,bj,pushPosx,pushPosy,record))
                    continue;//不能从当前位置到达推箱子位置
                state.push = push+1;
                state.bi = nextbi;
                state.bj = nextbj;
                state.pi = nextpi;
                state.pj = nextpj;
                if(vis.find(state) == vis.end())
                {
                    vis.insert(state);
                    cout << state.push << " ";
                    cout << state.bi  << " ";
                    cout << state.bj  << " ";
                    cout << state.pi  << " ";
                    cout << state.pj  << endl;
                    q.push(state);
                }
            }
        }
        return -1;
    }
    bool canReachPushPos(vector<vector<char>>& grid, int x0, int y0, int bi, int bj, int tx, int ty, vector<vector<bool>>& vis)
    {
        vis[x0][y0] = true;
        if(x0==tx && y0==ty) return true;
        int m = grid.size(), n = grid[0].size();
        for(int k = 0; k < 4; k++)
        {
            int nx = x0+dir[k][0];
            int ny = y0+dir[k][1];
            if(nx>=0 && nx<m && ny>=0 && ny<n && grid[nx][ny] != '#'
               && !(nx==bi && ny==bj) && !vis[nx][ny])
            {   // box 也不能穿过
                if(canReachPushPos(grid,nx, ny,bi,bj,tx,ty, vis))
                    return true;
            }
        }
        return false;
    }
};


int main()
{

    Solution s;
    vector<vector<char>> g = {{'#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#'},{'#','.','.','.','.','.','.','.','.','.','.','.','#','#','#','#'},{'#','.','#','#','#','#','.','#','#','#','#','.','#','#','#','.'},{'#','.','.','.','.','.','.','#','T','#','.','.','#','#','#','.'},{'#','.','.','.','#','.','.','.','.','.','.','.','#','#','#','.'},{'#','.','.','.','.','.','B','.','.','.','.','.','#','#','#','.'},{'#','.','#','#','#','#','#','#','#','#','#','.','#','#','#','.'},{'#','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.'},{'#','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.'},{'#','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.'},{'#','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.'},{'#','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.'},{'#','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.'},{'#','.','.','.','.','.','.','.','S','.','.','.','.','.','.','.'},{'#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#'}};
    vector<int> a = {4,2,4,8,2}, b = {5,5,5,10,8}, c={1,2,8,10,4};
    string s1 = "D450";
    cout << s.minPushBox(g) << endl;


    return 0;
}