class Solution {
    int m, n;
    vector<vector<int>> dir = {{1,0},{0,1},{0,-1},{-1,0}};
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        m = heights.size(), n = heights[0].size();
        int l = 0, r = 1e6, mid, ans = 0;
        while(l <= r)
        {
            mid = l + ((r-l)>>1);
            vector<vector<bool>> vis(m, vector<bool>(n,false));
            if(dfs(heights, vis, 0, 0, mid))
            {
                r = mid-1;
                ans = mid;
            }
            else
                l = mid+1;
        }
        return ans;
    }
    bool dfs(vector<vector<int>>& heights, vector<vector<bool>>& vis, int x, int y, int d)
    {
        if(x == m-1 && y == n-1)
            return true;
        vis[x][y] = true;
        int i, j, k;
        for(k = 0; k < 4; k++)
        {
            i = x + dir[k][0];
            j = y + dir[k][1];
            if(i>=0 && i<m && j>=0 && j<n && !vis[i][j]
                    && abs(heights[x][y]-heights[i][j]) <= d)
            {
                if(dfs(heights, vis, i, j, d))
                    return true;
            }
        }
        return false;
    }
};