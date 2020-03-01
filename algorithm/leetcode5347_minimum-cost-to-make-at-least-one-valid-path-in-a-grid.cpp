class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int m = grid.size(), n= grid[0].size();
        int i, j, x = 0, y = 0, a, b, k, flip = 0, size;
        vector<vector<int>> dir = {{0,0},{0,1},{0,-1},{1,0},{-1,0}};
        vector<vector<bool>> visited(m,vector<bool>(n,false));
        queue<pair<int,int>> q;
        while(x>=0 && x<m && y>=0 && y<n && !visited[x][y])
        {
            q.push({x,y});
            visited[x][y] = true;
            i = x + dir[grid[x][y]][0];
            j = y + dir[grid[x][y]][1];
            x = i, y = j;
        }
        if(visited[m-1][n-1])
            return 0;
        while(!q.empty())
        {
            size = q.size();
            flip++;
            while(size--)
            {
                i = q.front().first;
                j = q.front().second;
                q.pop();
                for(k = 1; k <= 4; k++)
                {
                    x = i + dir[k][0];
                    y = j + dir[k][1];
                    while(x>=0 && x<m && y>=0 && y<n && !visited[x][y])
                    {
                        q.push({x,y});
                        visited[x][y] = true;
                        a = x + dir[grid[x][y]][0];
                        b = y + dir[grid[x][y]][1];
                        x = a, y = b;
                    }
                }
            }
            if(visited[m-1][n-1])
                return flip;
        }
        return flip;
    }
};