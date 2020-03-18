class Solution {
	int m, n, step = INT_MAX;
	vector<int> start;
    vector<int> end;
    int bao = 0, count = 0;
    vector<vector<int>> dir = {{1,0},{-1,0},{0,1},{0,-1}};
public:
    int minSteps(vector<string> &maze) {
        int i, j, k, x, y, x0, y0;
        m = maze.size(), n = maze[0].size();
        queue<vector<int>> q;
        vector<int> tp;
        bool foundT = false;
        
        vector<vector<bool>> vis(m, vector<bool>(n,false));
        for(i = 0; i < m; ++i)
        {
        	for(j = 0; j < n; ++j)
        	{
        		if(maze[i][j] == 'S')
        		{
        			start.push_back(i);
        			start.push_back(j);
        		}
        		else if(maze[i][j] == 'T')
        		{
        			end.push_back(i);
        			end.push_back(j);
        		}
        		else if(isdigit(maze[i][j]))
        		{
        			bao++;
        		}
        	}
        }
        q.push(start);
        vis[start[0]][start[1]] = true;
        while(!q.empty())
        {
        	tp = q.front();
        	q.pop();
        	x0 = tp[0], y0 = tp[1];
        	for(k = 0; k < 4; ++k)
        	{
        		x = x0+dir[k][0];
        		y = y0+dir[k][1];
        		if(x>=0&&x<m&&y>=0&&y<n&&maze[x][y]!='*'&&!vis[x][y])
        		{
        			q.push({x,y});
        			vis[x][y] = true;
        			if(isdigit(maze[x][y]))
        				count++;
        			else if(maze[x][y]=='T')
        				foundT = true;
        		}
        	}
        }
        if(count!=bao || !foundT)
        	return -1;
        vis.resize(m, vector<bool>(n,false));
        vis[start[0]][start[1]] = true;
        dfs(start[0],start[1],0,0,vis,maze);
        return step;
    }

    void dfs(int x, int y, int count,int s, vector<vector<bool>> &vis,vector<string> &maze)
    {
    	if(count == bao && x==end[0] && y==end[1])
    	{
    		step = min(step, s);
    		return;
    	}
    	int xi, yi;
    	for(int k = 0; k < 4; ++k)
    	{
    		xi = x +dir[k][0];
    		yi = y + dir[k][1];
    		if(xi>=0&&xi<m&&yi>=0&&yi<n&&maze[xi][yi]!='*'&&!vis[xi][yi])
    		{
    			vis[xi][yi] = true;
    			if(isdigit(maze[xi][yi]))
    				count++;
    			dfs(xi,yi,count,s+1,vis,maze);
    			vis[xi][yi] = false;
    			if(isdigit(maze[xi][yi]))
    				count--;
    		}
    	}
    }
};