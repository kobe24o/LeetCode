#include <vector>
using namespace std;
class Solution {
    int sx,sy,ex,ey;//起点终点坐标
    int m,n,steps = 0;
    vector<vector<int>> dir = {{-1,0},{1,0},{0,1},{0,-1}};
public:
    int uniquePathsIII(vector<vector<int>>& grid) {
        int i, j;
        m = grid.size(), n = grid[0].size();
        for(i = 0; i < m; ++i)
            for(j = 0; j < n; ++j)
            {
                if(grid[i][j] != -1)
                    steps++;//计算需要走的空白步数
                if(grid[i][j] == 1)
                    sx = i, sy = j;
                else if(grid[i][j] == 2)
                    ex = i, ey = j;
            }
        int paths = 0;
        grid[sx][sy] = -1;//起点标记走过了
        dfs(grid, sx, sy, 1, paths);
        return paths;
    }

    void dfs(vector<vector<int>>& grid, int x, int y, int step, int &paths) 
    {
        if(x == ex && y == ey)
        {
            if(step == steps)
                paths++;
            return;
        }
        int x0, y0, origin;
        for(int k = 0; k < 4; ++k)
        {
            x0 = x+dir[k][0];
            y0 = y+dir[k][1];
            if(x0 >= 0 && x0 < m && y0 >= 0 && y0 < n && grid[x0][y0] != -1)
            {
                origin = grid[x0][y0];
                grid[x0][y0] = -1;
                dfs(grid,x0,y0,step+1,paths);
                grid[x0][y0] = origin;
            }
        }
    }
};
int main()
{
	Solution s;
//	vector<vector<int>> g ={{1,0,0,0},{0,0,0,0},{0,0,2,-1}};
    vector<vector<int>> g ={{1,0},{2,0}};
    s.uniquePathsIII(g);
}