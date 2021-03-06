struct point
{
	int x;
	int y;
	int val;
	point(int x0, int y0, int v)
	{
		x = x0;
		y = y0;
		val = v;
	}
};
struct cmp
{
    bool operator()(point& a, point& b) 
    {
        return a.val < b.val;
    }
};
class Solution {
	vector<vector<int>> dir = {{1,0},{0,1},{0,-1},{-1,0}};
public:
    int maximumMinimumPath(vector<vector<int>>& A) {
        int m = A.size(), n = A[0].size(), i, j, x, y, k, ans = A[0][0];
        vector<vector<bool>> visited(m, vector<bool>(n,false));
        visited[0][0] = true;
        priority_queue<point,vector<point>,cmp> q;
        q.push(point(0, 0, A[0][0]));
        while(!q.empty())
        {
        	ans = min(ans, q.top().val);
        	i = q.top().x;
        	j = q.top().y;
        	q.pop();
        	if(i==m-1 && j==n-1)
        		return ans;
        	for(k = 0; k < 4; ++k)
        	{
        		x = i + dir[k][0];
        		y = j + dir[k][1];
        		if(x>=0 && x<m && y>=0 && y<n && !visited[x][y])
        		{
        			q.push(point(x, y, A[x][y]));
        			visited[x][y] = true;
        		}
        	}
        }
        return ans;
    }
};


class Solution {
	vector<vector<int>> dir = {{1,0},{0,1},{0,-1},{-1,0}};
	int m, n, ans;
public:
    int maximumMinimumPath(vector<vector<int>>& A) {
        m = A.size(), n = A[0].size();
        int l = 0, r = min(A[0][0], A[m-1][n-1]);
        while(l <= r)
        {
        	vector<vector<bool>> visited(m, vector<bool>(n,false));
        	int midval = (l+r)/2;
        	if(canfindpath(A,visited,0,0,midval))//能找到任意一条路径，其所有值都大于等于 midval
        	{
        		ans = midval;
        		l = midval + 1;
        	}
        	else
        		r = midval-1;
        }	
        return ans;
    }

    bool canfindpath(vector<vector<int>>& A, vector<vector<bool>>& visited, int i, int j, int v)
    {
    	int x, y, k;
    	visited[i][j] = true;
    	if(i==m-1 && j==n-1)
    		return true;
    	for(k = 0; k < 4; ++k)
    	{
    		x = i + dir[k][0];
    		y = j + dir[k][1];
    		if(x>=0 && x<m && y>=0 && y<n && !visited[x][y] && A[x][y] >= v)
    		{
    			if(canfindpath(A, visited,x,y,v))
    				return true;
    		}
    	}
    	return false;
    }
};