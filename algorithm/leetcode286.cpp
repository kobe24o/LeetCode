class Solution {//超时
public:
    void wallsAndGates(vector<vector<int>>& rooms) {
        if(rooms.size()==0 || rooms[0].size()==0) return;
        int INF = INT_MAX, i, j, k,step,size,x,y,nx,ny;
        int m = rooms.size(), n = rooms[0].size();
        vector<vector<int>> dir = {{1,0},{0,1},{0,-1},{-1,0}};
        for(i = 0; i < m; ++i)
        {
        	for(j = 0; j < n; ++j)
        	{
        		if(rooms[i][j]!=INF)
        			continue;
        		vector<vector<bool>> visited(m, vector<bool>(n,false));
        		visited[i][j] = true;
        		queue<vector<int>> q;
        		q.push({i,j});
        		step = 0;
        		bool found = false;
        		while(!q.empty())
        		{
        			size = q.size();
        			while(size--)
        			{
	        			x = q.front()[0];
	        			y = q.front()[1];
	        			q.pop();
	        			if(rooms[x][y]==0)
	        			{
	        				rooms[i][j] = step;
	        				found = true;
	        				break;
	        			}
	        			for(k = 0; k < 4; ++k)
	        			{
	        				nx = x + dir[k][0];
	        				ny = y + dir[k][1];
	        				if(nx>=0 && nx<m && ny>=0 && ny<n 
	        					&& !visited[nx][ny] && rooms[nx][ny] != -1)
	        				{
	        					q.push({nx,ny});
	        					visited[nx][ny] = true;
	        				}
	        			}
	        		}
	        		if(found)
	        			break;
	        		step++;
        		}
        	}
        }
    }
};

class Solution {
public:
    void wallsAndGates(vector<vector<int>>& rooms) {
        if(rooms.size()==0 || rooms[0].size()==0) return;
        int INF = INT_MAX, i, j, k,step = 0,size,x,y,nx,ny;
        int m = rooms.size(), n = rooms[0].size();
        vector<vector<int>> dir = {{1,0},{0,1},{0,-1},{-1,0}};
        vector<vector<bool>> visited(m, vector<bool>(n,false));        
        queue<vector<int>> q;
        for(i = 0; i < m; ++i)
        {
        	for(j = 0; j < n; ++j)
        	{
        		if(rooms[i][j]==0)
        		{
                    visited[i][j] = true;
                    q.push({i,j});
                }
            }
        }
        while(!q.empty())
        {	
        	size = q.size();
            while(size--)
            {
                x = q.front()[0];
                y = q.front()[1];
                q.pop();
                if(rooms[x][y]==INF)
                {
                    rooms[x][y] = step;
                }
                for(k = 0; k < 4; ++k)
                {
                    nx = x + dir[k][0];
                    ny = y + dir[k][1];
                    if(nx>=0 && nx<m && ny>=0 && ny<n 
                        && !visited[nx][ny] && rooms[nx][ny] != -1)
                    {
                        q.push({nx,ny});
                        visited[nx][ny] = true;
                    }
                }
            }
            step++;
        }
    }
};