class Solution {
	int m, n;
	int ans = INT_MAX;
	vector<vector<int>> dir = {{1,0},{0,1},{0,-1},{-1,0}};
public:
    int maximumMinimumPath(vector<vector<int>>& A) {
        m = A.size(), n = A[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n,false));
        visited[0][0] = true;
        dfs(0,0,A, A[0][0], visited);
        return ans;
    }
    void dfs(int x, int y, vector<vector<int>>& A, int minpoint, vector<vector<bool>>& visited)
    {
    	if(ans != INT_MAX)
    		return;
    	minpoint = min(minpoint, A[x][y]);
    	if(x==m-1 && y==n-1)
    	{
    		ans = minpoint;
    		return;
    	}
    	int i,j,k, nx, ny, maxval = 0;
    	vector<vector<int>> around;
    	for(k = 0; k < 4; ++k)
    	{
    		i = x + dir[k][0];
    		j = y + dir[k][1];
    		if(i>=0 && i<m && j>=0 && j<n && !visited[i][j])
    			around.push_back({i,j});
    	}
    	sort(around.begin(), around.end(),[&](auto a, auto b){
    		return A[a[0]][a[1]] > A[b[0]][b[1]];
    	});
    	for(auto& pos : around)
    	{
    		visited[pos[0]][pos[1]] = true;
    		dfs(pos[0],pos[1],A,min(minpoint,A[pos[0]][pos[1]]),visited);
    	}
    	
    }
};