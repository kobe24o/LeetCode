class Solution {
    vector<vector<int>> dir = {{-1,0},{0,1},{0,-1},{1,0}};
    int m, n;
public:
    int minDays(vector<vector<int>>& grid) {
        m = grid.size(), n = grid[0].size();
        int island = computeIsland(grid);
        if(island == 0 || island > 1)
            return 0;
        for(int i = 0, j; i < m; ++i)
        {
            for(j = 0; j < n; ++j)
            {
                if(grid[i][j] == 0)
                    continue;
                grid[i][j] = 0;//将这个土地变成水
                island = computeIsland(grid);
                if(island == 0 || island > 1)
                    return 1;
                grid[i][j] = 1;//回溯
            }
        }
        return 2;
    }

    int computeIsland(vector<vector<int>>& grid)
    {
        int island = 0;
        vector<vector<bool>> vis(m, vector<bool>(n, false));
        for(int i = 0, j; i < m; ++i)
        {
            for(j = 0; j < n; ++j)
            {
                if(grid[i][j] == 0 || vis[i][j])
                    continue;
                island++;
                vis[i][j] = true;
                dfs(grid, i, j, vis);
            }
        }
        return island;
    }
    void dfs(vector<vector<int>>&grid, int i, int j, vector<vector<bool>>& vis)
    {
        int x, y, k;
        for(k = 0; k < 4; k++) 
        {
            x = i + dir[k][0];
            y = j + dir[k][1];
            if(x>=0 && x<m && y>=0 && y<n && !vis[x][y] && grid[x][y])
            {
                vis[x][y] = true;
                dfs(grid, x, y, vis);
            }
        }
    }
};
