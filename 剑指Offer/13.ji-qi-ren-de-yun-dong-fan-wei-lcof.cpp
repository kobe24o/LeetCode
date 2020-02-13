class Solution {
public:
    int movingCount(int m, int n, int k) {
        vector<vector<bool>> visited(m, vector<bool>(n,false));
        vector<vector<int>> dir = {{-1,0},{1,0},{0,1},{0,-1}};
        queue<vector<int>> q;
        q.push({0,0});
        visited[0][0] = true;
        int count = 1, tpx, tpy, x, y, i;
        while(!q.empty())
        {
        	tpx = q.front()[0];
        	tpy = q.front()[1];
        	q.pop();
        	for(i = 0; i < 4; ++i)
        	{
        		x = tpx+dir[i][0];
        		y = tpy+dir[i][1];
        		if(x>=0 && x<m && y>=0 && y<n && !visited[x][y] && valid(x,y,k))
	        	{
	        		q.push({x,y});
	        		visited[x][y] = true;
	        		count++;
	        	}
	        }	        
        }
        return count;
    }

    bool valid(int x, int y, int &k)
    {
    	int sum = 0;
    	while(x)
    	{
    		sum += (x%10);
    		x /= 10;
    	}
    	while(y)
    	{
    		sum += (y%10);
    		y /= 10;
    	}
    	return (sum<=k);
    }
};

class Solution {
    vector<vector<int>> dir = {{-1,0},{1,0},{0,1},{0,-1}};
public:
    int movingCount(int m, int n, int k) {
        vector<vector<bool>> visited(m, vector<bool>(n,false));
        int count = 1;
        visited[0][0] = true;
        dfs(0,0,count,visited,m,n,k);
        return count;
    }
    void dfs(int i, int j, int& count, vector<vector<bool>>& visited,int& m, int& n, int& k)
    {
    	int x, y;
    	for(int a = 0; a < 4; ++a)
    	{
    		x = i+dir[a][0];
    		y = j+dir[a][1];
    		if(x >=0 && x<m && y>=0 && y<n && !visited[x][y] && valid(x,y,k))
    		{
    			visited[x][y] = true;
    			count++;
    			dfs(x,y,count,visited,m,n,k);
    		}
    	}
    }
    bool valid(int x, int y, int &k)
    {
    	int sum = 0;
    	while(x)
    	{
    		sum += (x%10);
    		x /= 10;
    	}
    	while(y)
    	{
    		sum += (y%10);
    		y /= 10;
    	}
    	return (sum<=k);
    }
};