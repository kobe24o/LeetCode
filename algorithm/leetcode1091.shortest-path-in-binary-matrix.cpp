class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
    	int m = grid.size(), n = grid[0].size(), i, j, x, y, k, step = 1, size;
    	if(grid[0][0]==1 || grid[m-1][n-1]==1)
    		return -1;
    	vector<vector<int>> dir = {{1,0},{0,1},{0,-1},{-1,0},{1,1},{-1,-1},{1,-1},{-1,1}};
    	queue<vector<int>> q;
    	q.push({0,0});//坐标x,y
    	grid[0][0] = 1;//访问过
    	while(!q.empty())
    	{
            size = q.size();
            while(size--)
            {
                i = q.front()[0];
                j = q.front()[1];
                if(i==m-1 && j==n-1)
                    return step;
                q.pop();
                for(k = 0; k < 8; ++k)
                {
                    x = i + dir[k][0];
                    y = j + dir[k][1];
                    if(x>=0 && x<m && y>=0 && y<n && grid[x][y]==0)
                    {
                        q.push({x,y});
                        grid[x][y] = 1;//访问过了
                    }
                }
            }
    		step++;
    	}
    	return -1;
    }
};