class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int m = isWater.size(), n = isWater[0].size();
        queue<pair<int,int>> q;
        vector<vector<bool>> vis(m, vector<bool>(n, false));
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++)
                if(isWater[i][j]) // 是水
                {
                    q.push({i,j});
                    vis[i][j] = true;
                }
        }
        vector<vector<int>> dir = {{1,0},{0,1},{-1, 0},{0,-1}};
        int h = 0;
        while(!q.empty())
        {
            int size = q.size();
            while(size--)
            {
                pair<int,int> t = q.front();
                q.pop();
                isWater[t.first][t.second] = h;
                for(int k = 0; k < 4; ++k)
                {
                    int x = t.first+dir[k][0];
                    int y = t.second+dir[k][1];
                    if(x>=0 && x < m && y>=0 && y < n && !vis[x][y])
                    {
                        q.push({x,y});
                        vis[x][y] = true;
                    }
                }
            }
            h++;
        }
        return isWater;
    }
};