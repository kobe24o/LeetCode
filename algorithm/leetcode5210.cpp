class Solution {
public:
    vector<int> findBall(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<int> ans(n, -1);
        for(int j = 0; j < n; j++) 
        {
            int x = 0, y = j;
            while(x != m)
            {
                if(grid[x][y] == 1 && y == n-1)
                    break;//右边有墙
                else if(grid[x][y] == -1 && y == 0)
                    break;//左边有墙
                else if(grid[x][y] == 1 && grid[x][y+1] == -1)
                    break;//V字形的左边
                else if(grid[x][y] == -1 && grid[x][y-1] == 1)
                    break;//V字形的右边
                else if(grid[x][y] == 1)
                    x++,y++;//向右下走
                else
                    x++,y--;//向左下走
            }
            if(x == m)
                ans[j] = y;
        }
        return ans;
    }
};