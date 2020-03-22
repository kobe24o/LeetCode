class Solution {
	vector<vector<int>> d = {{0,1},{1,0},{-1,0},{0,-1}};//右0，下1，上2，左3
	vector<vector<vector<int>>> dir = {{},{d[0],d[3]},{d[1],d[2]},{d[1],d[3]},{d[0],d[1]},{d[2],d[3]},{d[0],d[2]}};
	//网格可走的方向
	int m,n;
public:
    bool hasValidPath(vector<vector<int>>& grid) {
        m = grid.size(), n = grid[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n,false));
        visited[0][0] = true;
        queue<vector<int>> q;
        q.push({0,0});
        int x,y,x0,y0,k,dx,dy;
        while(!q.empty())
        {
        	x0 = q.front()[0];
        	y0 = q.front()[1];
        	if(x0==m-1 && y0==n-1)
        		return true;
        	q.pop();
        	for(k = 0; k < dir[grid[x0][y0]].size(); ++k)
        	{	//网格可走方向
        		dx = dir[grid[x0][y0]][k][0];
        		dy = dir[grid[x0][y0]][k][1];
        		x = x0+dx;
        		y = y0+dy;
        		if(x>=0 && x<m && y>=0 && y<n && !visited[x][y] && isok(grid,dx,dy,x,y))
        		{
        			visited[x][y] = true;
        			q.push({x,y});
        		}
        	}
        }
        return false;
    }

    bool isok(vector<vector<int>>& grid, int &dx, int &dy, int &x, int &y)
    {	//dx dy 走过来的方向，在位置 x y 中有对应的接口，则可以走过来
    	if(dx == 1 && dy ==0)//往下走，对应x,y处 '上' 要开着
    	{
    		if(grid[x][y]==2 || grid[x][y]==5 || grid[x][y]==6)
    			return true;
    	}
    	else if(dx == 0 && dy == 1)//右   --左
    	{
    		if(grid[x][y]==1 || grid[x][y]==3 || grid[x][y]==5)
    			return true;
    	}
    	else if(dx == -1 && dy == 0)//上 ---下
    	{
    		if(grid[x][y]==2 || grid[x][y]==3 || grid[x][y]==4)
    			return true;
    	}
    	else if(dx == 0 && dy == -1)//左--- 右
    	{
    		if(grid[x][y]==1 || grid[x][y]==4 || grid[x][y]==6)
    			return true;
    	}
    	return false;
    }
};