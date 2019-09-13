class Solution {
public:
    int findCircleNum(vector<vector<int>>& M) {
        int n = M.size(), groups = 0, i;
        bool visited[n] = {false};
        for(i = 0; i < n; ++i)
        {
        	if(!visited[i])
        	{
        		bfs(M, visited, n, i);
        		++groups;
        	}
        }
        return groups;
    }
    void bfs(vector<vector<int>>& M, bool *visited, int &n, int idx) 
    {
    	queue<int> q;
    	q.push(idx);
    	visited[idx] = true;
    	int i, j;
    	while(!q.empty())
    	{
    		i = q.front();
    		for(j = 0; j < n; ++j)
    		{
    			if(M[i][j] && !visited[j])
    			{
    				visited[j] = true;
    				q.push(j);
    			}
    		}
    	}
    }
};

class Solution {
public:
    int findCircleNum(vector<vector<int>>& M) {
        int n = M.size(), groups = 0, i;
        bool visited[n] = {false};
        for(i = 0; i < n; ++i)
        {
        	if(!visited[i])
        	{
        		dfs(M, visited, n, i);
        		++groups;
        	}
        }
        return groups;
    }
    void dfs(vector<vector<int>>& M, bool *visited, int &n, int idx) 
    {
    	visited[idx] = true;
		for(int j = 0; j < n; ++j)
		{
			if(M[idx][j] && !visited[j])
			{
				dfs(M, visited, n, j);
			}
		}
    }
};