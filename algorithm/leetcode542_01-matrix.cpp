class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        int i, j, dis = 0, r, c, n, xf, yf, x, y, k;
        r = matrix.size(), c = matrix[0].size();
        vector<vector<int>> dir = {{0,1},{0,-1},{1,0},{-1,0}};
        vector<vector<bool>> visited(r,vector<bool>(c,false));
        queue<pair<int,int>> q;
        for(i = 0; i < r; ++i)
        {
        	for(j = 0; j < c; ++j)
        	{
        		if(matrix[i][j] == 0)
        			q.push({i, j});
        	}
        }
        while(!q.empty())
		{
			n = q.size();
			++dis;
			while(n--)
			{
				xf = q.front().first;
				yf = q.front().second;
				q.pop();
				for(k = 0; k < 4; ++k)
				{
					x = xf+dir[k][0];
	        		y = yf+dir[k][1];
	        		if(x>=0 && x<r && y>=0 && y<c && !visited[x][y] && matrix[x][y] != 0)
		        	{
	        			q.push({x,y});
	        			visited[x][y] = true;
	        			matrix[x][y] = dis;
		        	}
				}
			}
		}
        return matrix;
    }
};

class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) 
    {
        int r = matrix.size(), c = matrix[0].size(), i, j;
        if (r == 0)
            return matrix;
        vector<vector<int>> dist(r, vector<int>(c, INT_MAX-100000));//防止溢出
        //边界上的1元素距离外面无穷大
        //考虑左边和上边方向
        for (i = 0; i < r; i++) 
        {
            for (j = 0; j < c; j++) 
            {
                if (matrix[i][j] == 0)
                    dist[i][j] = 0;
                else 
                {
                    if (i > 0)
                        dist[i][j] = min(dist[i][j], dist[i-1][j]+1);
                    if (j > 0)
                        dist[i][j] = min(dist[i][j], dist[i][j-1]+1);
                }
            }
        }

        //考虑右边和下边方向
        for (i = r-1; i >= 0; i--) 
        {
            for (j = c-1; j >= 0; j--) 
            {
                if (i < r-1)
                    dist[i][j] = min(dist[i][j], dist[i+1][j]+1);
                if (j < c-1)
                    dist[i][j] = min(dist[i][j], dist[i][j+1]+1);
            }
        }
        return dist;
    }
};