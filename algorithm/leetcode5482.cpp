class Solution {
    vector<vector<int>> dir = {{1,0},{0,1},{-1,0},{0,-1}};
    bool found = false;
    int m, n;
public:
    bool containsCycle(vector<vector<char>>& grid) {
        m = grid.size(), n = grid[0].size();
        int i, j, k, x, y;
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        vector<vector<int>> step(m, vector<int>(n, 0));
        for(i = 0; i < m; ++i) 
        {
            for(j = 0; j < n; ++j)
            {
                if(found) return found;
                if(visited[i][j])
                    continue;
                visited[i][j] = true;
                step[i][j] = 1;//走过的步数
                dfs(i,j,step,visited,grid);
            }
        }
        return found;
    }
    void dfs(int i, int j,vector<vector<int>> &step, vector<vector<bool>> &visited, vector<vector<char>>& grid)
    {
        int x,y,k;
        if(found) return;
        for(k = 0; k < 4; k++)
        {
            x = i + dir[k][0];
            y = j + dir[k][1];
            if(x >= 0 && x < m && y >= 0 && y < n)
            {
                if(grid[x][y] != grid[i][j])
                    continue;//不相同的值，不行
                if(!visited[x][y])//没有访问
                {
                    visited[x][y] = true;
                    step[x][y] = step[i][j]+1;//步数+1
                    dfs(x, y, step, visited, grid);
                }
                else
                {	//访问过了，且当前步数跟其步数差满足条件
                    if(step[i][j]-step[x][y]+1 >= 4)
                    {
                        found = true;
                        return;
                    }
                }
            }
        }
    }
};
