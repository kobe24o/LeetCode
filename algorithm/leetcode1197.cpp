class Solution {
public:
    int minKnightMoves(int x, int y) {
    	vector<vector<int>> dir = {{2, 1},{2,-1},{-2,1},{-2,-1},{1,2},{1,-2},{-1,2},{-1,-2}};
    	x = abs(x), y = abs(y);
    	int m = x+20, n = y+20;
    	vector<vector<bool>> visited(m, vector<bool>(n,false));
    	x += 10, y += 10;
    	queue<vector<int>> q;
    	q.push({10,10});
    	visited[10][10] = true;
    	int step = 0, size, i, j, k, ni, nj;
    	while(!q.empty())
    	{
    		size = q.size();
    		while(size--)
    		{
    			i = q.front()[0];
    			j = q.front()[1];
    			if(i==x && j==y)
    				return step;
    			q.pop();
    			for(k = 0; k < 8; k++)
    			{
    				ni = i + dir[k][0];
    				nj = j + dir[k][1];
    				if(ni>=0 && ni<m && nj>=0 && nj<n && !visited[ni][nj])
    				{
    					q.push({ni,nj});
    					visited[ni][nj] = true;
    				}
    			}
    		}
    		step++;
    	}
    	return -1;
    }
};