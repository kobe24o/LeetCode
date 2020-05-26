class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int i, j, m = grid.size(), n = grid[0].size(), ans = 0;
        vector<int> countR(m,0), countC(n,0);
        for(i = 0; i < m; ++i)
            for(j = 0; j < n; ++j)
                if(grid[i][j]==1)
                {
                    countR[i]++;
                    countC[j]++;
                }
        for(i = 0; i < m; ++i)
            for(j = 0; j < n; ++j)
                if(grid[i][j]==1 && (countR[i]>1 || countC[j]>1))
                    ans++;
        return ans;
    }
};