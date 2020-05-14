class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
    	unordered_map<int, unordered_set<int>> m;
    	vector<int> indegree(numCourses, 0);
    	for(auto& pre : prerequisites)
    	{
    		m[pre[1]].insert(pre[0]);
    		indegree[pre[0]]++;
    	}
    	queue<int> q;
    	int tp, finish = 0, i;
    	for(i = 0; i < numCourses; ++i)
    		if(indegree[i] == 0)
    			q.push(i);
    	vector<int> ans(numCourses);
    	i = 0;
		while(!q.empty())
		{
			tp = q.front();
			finish++;
			ans[i++] = tp;
			q.pop();
			for(auto id : m[tp])
			{
				if(--indegree[id] == 0)
					q.push(id);
			}
		}
		if(i != numCourses)
			return {};
		return ans;
    }
};

class Solution {
    unordered_map<int, unordered_set<int>> m;
    vector<int> ans;
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
    	ans.resize(numCourses);
    	for(auto& pre : prerequisites)
    		m[pre[1]].insert(pre[0]);
        bool can = true;
        vector<int> visited(numCourses,0);
        int order = 0;
    	for(int i = 0; i < numCourses; ++i)
        {
            dfs(i, order, visited, can);
            if(!can)
                return {};
        }
        return ans;
    }

    void dfs(int i, int& order, vector<int> & visited, bool &can)
    {
        if(!can) return;
        if(visited[i]==2) return;
        if(visited[i]==1)
        {
            can = false;
            return;
        }
        visited[i] = 1;
        ans[order++] = i;
        for(auto id : m[i])
            dfs(id, order, visited, can);
        visited[i] = 2;
    }
};