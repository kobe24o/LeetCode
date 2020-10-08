class Solution {
    vector<vector<int>> dir = {{0,1}, {1,0}};
    int n;
public:
    int minimumMoves(vector<vector<int>>& grid) {
        n = grid.size();
        if(grid[n-1][n-2] || grid[n-1][n-1])
            return -1;
        int state, nt, pos, d, nd, i, j, k, x, y, x1, y1, x2, y2;
        queue<int> q;
        //将xy坐标压缩为一个数，再乘以 101，+ 方位，全部压缩为一个数
        unordered_set<int> vis;
        q.push(0);// pos = (101*i + j)*101 + dir
        int step = 0, size;
        int target = (101*(n-1)+(n-2))*101;
        while(!q.empty())
        {
            size = q.size();
            while(size--)
            {
                state = q.front();
                q.pop();
                if(state == target)
                    return step;
                d = state%101;
                pos = state/101;
                i = pos/101;//原来尾巴位置
                j = pos%101;
                // cout << " i :" << i << " j: " << j << " d : " << d << endl;
                x = i+dir[d][0];//原来头的位置
                y = j+dir[d][1];

                // 直行，方向不变
                x1 = i+dir[d][0];//下一个尾巴占据的位置
                y1 = j+dir[d][1];
                x2 = x+ dir[d][0];//下一个头的位置
                y2 = y+ dir[d][1];
                nt = (101*x1+y1)*101+d;//下一个状态
                if(ok(x2, y2) && grid[x2][y2]== 0
                    && !vis.count(nt))
                {
                    vis.insert(nt);
                    q.push(nt);//下一个状态
                }
                // 平移，方向不变
                nd = d == 0 ? 1 : 0;
                x1 = i+dir[nd][0];//下一个尾巴占据的位置
                y1 = j+dir[nd][1];
                x2 = x+ dir[nd][0];//下一个头的位置
                y2 = y+ dir[nd][1];
                nt = (101*x1+y1)*101+d;//下一个状态
                if(ok(x1, y1) && grid[x1][y1]==0 
                    && ok(x2, y2) && grid[x2][y2]== 0
                    && !vis.count(nt))
                {
                    vis.insert(nt);
                    q.push(nt);
                }
                // 旋转，方向变化, 尾巴位置没变
                nt = state/101*101 + nd;//下一个位置的编码
                if(ok(x1, y1) && grid[x1][y1]==0 
                    && ok(x2, y2) && grid[x2][y2]== 0
                    && !vis.count(nt))
                {
                    vis.insert(nt);
                    q.push(nt);
                }
            }
            step++;
        }
        return -1;
    }
    bool ok(int x, int y)
    {
        return x>=0 && x < n && y>=0 && y<n;
    }
};