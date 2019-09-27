class Solution {
    vector<vector<int>> ans;
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<int> path;
        path.push_back(0);
        dfs(graph,0,path);
        return ans;
    }
    void dfs(vector<vector<int>> &graph, int i, vector<int> path)
    {	
    	if(i == graph.size()-1)
    	{
    		ans.push_back(path);
    		return;
    	}    	
    	for(int idx = 0; idx < graph[i].size(); idx++)
    	{
            path.push_back(graph[i][idx]);
    		dfs(graph, graph[i][idx], path);
    		path.pop_back();
    	}
    }
};