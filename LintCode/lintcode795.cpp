class Solution {
	int sum = 0;
	int r,c;
	vector<vector<int>> dir = {{1,0},{-1,0},{0,1},{0,-1}};
public:
    int uniquePaths(int m, int n) {
        if(m==0 || n==0)
        	return 0;
        r= m, c= n;
        vector<vector<int>> map(m,vector<int>(n,1));
        map[0][0] = 0;
        dfs(map,0,0);
        return sum;
    }

    void dfs(vector<vector<int>>& map, int i, int j)
    {
    	if(i==r-1 && j==c-1)
    	{
    		sum++;
    		return;
    	}
    	int x, y;
    	for(int k = 0; k < 4; ++k)
    	{
    		x = i+dir[k][0];
    		y = j+dir[k][1];
    		if(x>=0&&x<r&&y>=0&&y<c&&map[x][y])
    		{
    			map[x][y]=0;
    			dfs(map,x,y);
    			map[x][y]=1;
    		}
    	}
    }
};