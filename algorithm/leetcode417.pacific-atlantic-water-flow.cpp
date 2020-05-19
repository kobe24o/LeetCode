class Solution {
	vector<vector<int>> dir = {{1,0},{0,1},{0,-1},{-1,0}};
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& matrix) {
        if(matrix.empty() || matrix[0].empty())
            return {};
		int m = matrix.size(), n = matrix[0].size(), i, j, x, y, k, v;
		vector<vector<bool>> visited(m, vector<bool>(n,false));
		queue<vector<int>> q;
		for(i = 0; i < n; ++i)
		{
			q.push({0,i});
			visited[0][i] = true;
		}
		for(i = 1; i < m; ++i)
		{
			q.push({i,0});
			visited[i][0] = true;
		}
		while(!q.empty())
		{
			x = q.front()[0];
			y = q.front()[1];
			v = matrix[x][y];
			q.pop();
			for(k = 0; k < 4; ++k)
			{
				i = x + dir[k][0];
				j = y + dir[k][1];
				if(i>=0 && i<m && j>=0 && j<n && !visited[i][j] && v <= matrix[i][j])
				{
					q.push({i,j});
					visited[i][j] = true;
				}
			}
		}
		vector<vector<bool>> visited2(m, vector<bool>(n,false));
		for(i = 0; i < n; ++i)
		{
			q.push({m-1,i});
			visited2[m-1][i] = true;
		}
		for(i = 0; i < m-1; ++i)
		{
			q.push({i,n-1});
			visited2[i][n-1] = true;
		}
		while(!q.empty())
		{
			x = q.front()[0];
			y = q.front()[1];
			v = matrix[x][y];
			q.pop();
			for(k = 0; k < 4; ++k)
			{
				i = x + dir[k][0];
				j = y + dir[k][1];
				if(i>=0 && i<m && j>=0 && j<n && !visited2[i][j] && v <= matrix[i][j])
				{
					q.push({i,j});
					visited2[i][j] = true;
				}
			}
		}
		vector<vector<int>> ans;
		for(i = 0; i < m; ++i)
		{
			for(j = 0; j < n; ++j)
			{
				if(visited[i][j] && visited2[i][j])
					ans.push_back({i,j});
			}
		}
		return ans;
    }
};

class Solution {
	vector<vector<int>> dir = {{1,0},{0,1},{0,-1},{-1,0}};
    int m, n;
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& matrix) {
        if(matrix.empty() || matrix[0].empty())
            return {};
		m = matrix.size(), n = matrix[0].size();
        int i, j;
		vector<vector<bool>> visited(m, vector<bool>(n,false));
		for(i = 0; i < n; ++i)
		{
            if(!visited[0][i])
			{
                visited[0][i] = true;
                dfs(0,i,visited,matrix);
            }
		}
		for(i = 1; i < m; ++i)
		{
			if(!visited[i][0])
			{
                visited[i][0] = true;
                dfs(i,0,visited,matrix);
            }
		}
        vector<vector<bool>> visited2(m, vector<bool>(n,false));
        for(i = 0; i < n; ++i)
		{
			if(!visited2[m-1][i])
			{
                visited2[m-1][i] = true;
                dfs(m-1,i,visited2,matrix);
            }
		}
		for(i = 0; i < m-1; ++i)
		{
			if(!visited2[i][n-1])
			{
                visited2[i][n-1] = true;
                dfs(i,n-1,visited2,matrix);
            }
		}
        vector<vector<int>> ans;
		for(i = 0; i < m; ++i)
		{
			for(j = 0; j < n; ++j)
			{
				if(visited[i][j] && visited2[i][j])
					ans.push_back({i,j});
			}
		}
		return ans;
    }
    void dfs(int x, int y, vector<vector<bool>>& visited,vector<vector<int>>& matrix)
    {
        int i, j, v = matrix[x][y];
        for(int k = 0; k < 4; ++k)
        {
            i = x + dir[k][0];
            j = y + dir[k][1];
            if(i>=0 && i<m && j>=0 && j<n && !visited[i][j] && v <= matrix[i][j])
            {
                visited[i][j] = true;
                dfs(i, j, visited, matrix);
            }
        }	
    }
};