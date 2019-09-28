class Solution {
	int oldCol;
	int r,c;
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        oldCol = image[sr][sc];
        r = image.size();
        c = image[0].size();
        vector<vector<bool>> visited(r,vector<bool> (c,false));
        dfs(image, sr, sc, newColor,visited);
        return image;
    }
    void dfs(vector<vector<int>> &image, int sr, int sc, int &newColor, vector<vector<bool>> &visited)
    {
    	if((sr<0 || sr>=r)||(sc<0 || sc>=c))
    		return;
    	if(image[sr][sc] == oldCol && !visited[sr][sc])
    	{
    		image[sr][sc] = newColor;
    		visited[sr][sc] = true;
    		dfs(image, sr-1, sc, newColor,visited);
    		dfs(image, sr+1, sc, newColor,visited);
    		dfs(image, sr, sc-1, newColor,visited);
    		dfs(image, sr, sc+1, newColor,visited);
    	}
    }
};

class Solution {
	int oldCol;
	int r,c;
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        oldCol = image[sr][sc];
        r = image.size();
        c = image[0].size();
        vector<vector<bool>> visited(r,vector<bool> (c,false));
        vector<vector<int>> dir = {{0,1},{0,-1},{1,0},{-1,0}};
        queue<pair<int,int>> q;
        q.push({sr,sc});
        int xf, yf, x, y, i;
        visited[sr][sc] = true;
        while(!q.empty())
        {
        	xf = q.front().first;
        	yf = q.front().second;
        	image[xf][yf] = newColor;
        	q.pop();
        	for(i = 0; i < 4; ++i)
        	{
        		x = xf+dir[i][0];
        		y = yf+dir[i][1];
        		if((x>=0 && x<r)&&(y>=0 && y<c) && !visited[x][y] && image[x][y] == oldCol)
	        	{
	        		q.push({x,y});
	        		visited[x][y] = true;
	        	}
        	}  	
        }
        return image;
    }
};