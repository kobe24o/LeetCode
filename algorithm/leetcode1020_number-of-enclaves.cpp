class Solution {
	vector<vector<int>> dir = {{1,0},{0,1},{0,-1},{-1,0}};
	int m, n, x, y, k;
	int count;
	bool out;
	queue<pair<int,int>> q;
	pair<int,int> tp;
public:
    int numEnclaves(vector<vector<int>>& A) {
    	m = A.size(), n = A[0].size();
        int land = 0, i, j;
        for(i = 0; i < m; i++)
        {
        	for(j = 0; j < n; j++)
        	{
        		if(A[i][j] == 1)//陆地
        		{
        			land += bfs(A,i,j);
        		}
        	}
        }
        return land;
    }

    int bfs(vector<vector<int>>& A, int i, int j) 
    {
    	count = 0;
    	A[i][j] = 0;//访问过了
    	count++;//陆地计数+1
    	q.push({i,j});
    	bool out = (i==0||i==m-1||j==0||j==n-1);
    	while(!q.empty())
    	{
    		tp = q.front();
    		q.pop();
    		for(k = 0; k < 4; ++k)
    		{
    			x = tp.first + dir[k][0];
    			y = tp.second + dir[k][1];
    			if(x>=0 && x<m && y>=0 && y<n && A[x][y]==1)
    			{
    				A[x][y] = 0;
    				count++;
    				q.push({x,y});
    				if(!out && (x==0||x==m-1||y==0||y==n-1))
    					out = true;
    			}
    		}
    	}
    	if(out)
    		return 0;
    	return count;
    }
};

class Solution {
	vector<vector<int>> dir = {{1,0},{0,1},{0,-1},{-1,0}};
	int m, n;
public:
    int numEnclaves(vector<vector<int>>& A) {
    	m = A.size(), n = A[0].size();
        int land = 0, i, j;
        bool out;
        for(i = 0; i < m; i++)
        {
        	for(j = 0; j < n; j++)
        	{
        		if(A[i][j] == 1)//陆地
        		{
        			out = (i==0||i==m-1||j==0||j==n-1);
        			land += dfs(A,i,j,out);
        		}
        	}
        }
        return land;
    }

    int dfs(vector<vector<int>>& A, int i, int j, bool& out) 
    {
    	int x, y, k, count = 0;
    	A[i][j] = 0;//访问过了
    	count++;//陆地计数+1
		for(k = 0; k < 4; ++k)
		{
			x = i + dir[k][0];
			y = j + dir[k][1];
			if(x>=0 && x<m && y>=0 && y<n && A[x][y]==1)
			{
				A[x][y] = 0;
				if(!out && (x==0||x==m-1||y==0||y==n-1))
					out = true;
				count += dfs(A,x,y,out);
			}
		}
    	if(out)
    		return 0;
    	return count;
    }
};