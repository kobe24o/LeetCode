class Solution {
public:
    bool leadsToDestination(int n, vector<vector<int>>& edges, int source, int destination) {
    	vector<bool> visited(n, false);
    	vector<vector<int>> m(n);
    	for(auto& e : edges)
    		m[e[0]].push_back(e[1]);
    	if(!m[destination].empty())
    		return false;//终点后面还有路径
		return dfs(m,visited,source,destination);
    }
    bool dfs(vector<vector<int>>& m, vector<bool>& visited, int cur, int destination) 
    {
    	if(m[cur].size()==0 && cur != destination)
    		return false;
    	for(int next : m[cur])
    	{
    		if(visited[next])
    			return false;//有环
    		visited[next] = true;
    		if(!dfs(m, visited, next, destination))
    			return false;
    		visited[next] = false;
    	}
        return true;
    }
};