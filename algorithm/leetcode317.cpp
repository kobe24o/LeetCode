class Solution {
public:
    int shortestDistance(vector<vector<int>>& grid) {
    	//从每个建筑物出发去找空地，空地对每个建筑物的距离累积
    	vector<vector<int>> dir = {{1,0},{0,1},{0,-1},{-1,0}};
    	vector<vector<int>> build;
    	int i, j, k, x, y, mindis;
    	int m = grid.size(), n = grid[0].size();
    	for(i = 0; i < m; i++)
    		for(j = 0; j < n; j++)
    			if(grid[i][j]==1)
    				build.push_back({i,j});
    	vector<vector<int>> dis(m, vector<int>(n, 0));//记录单次遍历1个房屋到空地的距离
    	vector<vector<int>> totaldis(m, vector<int>(n, 0));//记录所有房屋到空地的距离
    	int emptyPlace = 0;
    	for(auto& pos : build)
    	{
    		queue<vector<int>> q;
    		// vector<vector<bool>> visited(m, vector<bool>(n,false));
    		q.push({pos[0], pos[1]});//x,y
    		mindis = INT_MAX;
    		while(!q.empty())
    		{
                x = q.front()[0];
                y = q.front()[1];
                q.pop();
                for(k = 0; k < 4; ++k)
                {
                    i = x + dir[k][0];
                    j = y + dir[k][1];
                    if(i>=0 && i<m && j>=0 && j<n && grid[i][j] == emptyPlace)
                    {
                        dis[i][j] = dis[x][y]+1;
                        totaldis[i][j] += dis[i][j];
                        mindis = min(mindis, totaldis[i][j]);
                        // visited[i][j] = true;
                        grid[i][j]--;//从lx_lx大佬那学的，不用开访问数组了
                        q.push({i,j});
                    }
                }
    		}
            if(mindis == INT_MAX)
                return -1;//该房屋不能到达任何空地
            emptyPlace--;
    	}
    	return mindis==INT_MAX ? -1 : mindis;
    }
};