class Solution {
    int x1 = INT_MAX, x2 = -1;
    int y1 = INT_MAX, y2 = -1;
public:
    int minArea(vector<vector<char>>& image, int x, int y) {
    	int m = image.size(), n = image[0].size(), i, j, nx, ny, k;
        vector<vector<int>> dir = {{1,0},{0,1},{0,-1},{-1,0}};
        queue<vector<int>> q;
        q.push({x,y});
        image[x][y] = '0';//访问过了
        while(!q.empty())
        {
        	i = q.front()[0];
        	j = q.front()[1];
        	q.pop();
        	x1 = min(x1, i);
        	x2 = max(x2, i);
        	y1 = min(y1, j);
        	y2 = max(y2, j);
        	for(k = 0; k < 4; ++k)
        	{
        		nx = i + dir[k][0];
        		ny = j + dir[k][1];
        		if(nx>=0 && nx<m && ny>=0 && ny<n && image[nx][ny]=='1')
        		{
        			q.push({nx, ny});
        			image[nx][ny] = '0';//访问过了
        		}
        	}
        }
        return (x2-x1+1)*(y2-y1+1);
    }
};