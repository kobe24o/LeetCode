class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int m = image.size(), n = image[0].size();
        int original = image[sr][sc], k, x, y, x0, y0;
        vector<vector<int>> dir = {{1,0},{0,1},{0,-1},{-1,0}};
        queue<vector<int>> q;
        vector<vector<bool>> visited(m, vector<bool>(n,false));
        q.push({sr,sc});
        visited[sr][sc] = true;
        image[sr][sc] = newColor;
        while(!q.empty())
        {
        	x0 = q.front()[0];
        	y0 = q.front()[1];
        	q.pop();
        	for(k = 0; k < 4; ++k)
        	{
        		x = x0+dir[k][0];
        		y = y0+dir[k][1];
        		if(x>=0 && x<m && y>=0 && y<n && !visited[x][y] && image[x][y]==original)
        		{
        			q.push({x,y});
        			visited[x][y] = true;
        			image[x][y] = newColor;
        		}
        	}
        }
        return image;
    }
};

class Solution {
	vector<vector<int>> dir = {{1,0},{0,1},{0,-1},{-1,0}};
	int m, n, original;
	vector<vector<bool>> visited;
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        m = image.size(), n = image[0].size();
        original = image[sr][sc];
        visited.resize(m, vector<bool>(n,false));
        visited[sr][sc] = true;
        image[sr][sc] = newColor;
        dfs(image,sr,sc,newColor);
        return image;
    }

    void dfs(vector<vector<int>>& image, int x0, int y0, int newColor)
    {
    	int x, y;
    	for(int k = 0; k < 4; ++k)
    	{
    		x = x0+dir[k][0];
    		y = y0+dir[k][1];
    		if(x>=0 && x<m && y>=0 && y<n && !visited[x][y] && image[x][y]==original)
    		{
    			visited[x][y] = true;
    			image[x][y] = newColor;
    			dfs(image,x,y,newColor);
    			//占领即可，不必回溯
    		}
    	}
    }
};