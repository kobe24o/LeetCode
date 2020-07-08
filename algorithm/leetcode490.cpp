class Solution {
public:
    bool hasPath(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
    	int m = maze.size(), n = maze[0].size(), i, j, k, x, y;
    	vector<vector<int>> dir = {{1,0},{0,1},{0,-1},{-1,0}};
    	queue<vector<int>> q;
    	vector<vector<bool>> visited(m, vector<bool>(n,false));
    	q.push(start);
    	visited[start[0]][start[1]] = true;
    	while(!q.empty())
    	{
    		i = q.front()[0];
    		j = q.front()[1];
    		q.pop();
            if(i==destination[0] && j==destination[1])
                return true;
    		for(k = 0; k < 4; ++k)
    		{
    			x = i;
	    		y = j;
    			while(x>=0 && x<m && y>=0 && y<n)
	    		{
                    if(!(x+dir[k][0]>=0 && x+dir[k][1]<m && y+dir[k][0]>=0 && y+dir[k][1]<n)
                        || visited[x+dir[k][0]][y+dir[k][0]] || maze[x+dir[k][0]][y+dir[k][0]]==1)
                        break;
	    			x += dir[k][0];
	    			y += dir[k][1];
                    visited[x][y] = true;
	    		}
                if(!visited[x][y])
	    		{
                    q.push({x, y});
                    visited[x][y] = true;
                }
    		}
    	}
    	return false;
    }
};