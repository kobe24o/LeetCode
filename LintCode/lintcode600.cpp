class Solution {
public:
    int minArea(vector<vector<char>> &image, int x, int y) {
        if(image.empty() || image[0].empty())
        	return 0;
        queue<vector<int>> q;
        q.push({x,y});
        image[x][y] = 'v';//标记走过了
        int m = image.size(), n = image[0].size();
        int l = x, r = x, u = y, b = y, i, j, k, i0, j0;
        vector<vector<int>> dir = {{0,1},{0,-1},{1,0},{-1,0}};//方向
        while(!q.empty())
        {
        	i0 = q.front()[0];
        	j0 = q.front()[1];
        	q.pop();
        	for(k = 0; k < 4; ++k)
        	{
        		i = i0+dir[k][0];
        		j = j0+dir[k][1];
        		if(i>=0 && i < m && j >=0&& j < n && image[i][j] != '0' && image[i][j] != 'v')
        		{
        			q.push({i,j});
        			image[i][j]='v';
        			l = min(l,i);//记录极限位置
        			r = max(r,i);
        			u = min(u,j);
        			b = max(b,j);
        		}
        	}
        }
        return (r-l+1)*(b-u+1);//返回面积
    }
};