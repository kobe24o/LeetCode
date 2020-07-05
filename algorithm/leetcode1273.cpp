class Solution {
public:
    int deleteTreeNodes(int nodes, vector<int>& parent, vector<int>& value) {
    	int i, n = parent.size();
    	vector<int> count(n,1);
    	for(i = n-1; i >= 0; --i)
    	{
    		if(value[i]==0)
    			count[i] = 0;
    		if(parent[i] != -1)
    		{
    			value[parent[i]] += value[i];
    			count[parent[i]] += count[i];
    		}
    	}
    	return count[0];
    }
};

class Solution {
public:
    int deleteTreeNodes(int nodes, vector<int>& parent, vector<int>& value) {
    	int i, n = parent.size();
    	vector<int> indegree(n,0);
    	for(i = 0; i < n; ++i)
    		if(parent[i] != -1)
    			indegree[parent[i]]++;
		queue<int> q;
		for(i = 0; i < n; ++i)
			if(indegree[i] == 0)
				q.push(i);
		vector<int> count(n,1);
		while(!q.empty())
		{
			int tp = q.front();
			q.pop();
			if(value[tp]==0)
				count[tp] = 0;
			if(parent[tp] == -1)
				continue;
			if(--indegree[parent[tp]]==0)
				q.push(parent[tp]);
			value[parent[tp]] += value[tp];
			count[parent[tp]] += count[tp];
		}
		return count[0];
    }
};

class Solution {
    vector<vector<int>> edges;
    vector<int> count;
public:
    int deleteTreeNodes(int nodes, vector<int>& parent, vector<int>& value) {
    	int i, n = parent.size();
    	edges.resize(n);
        count = vector<int>(n,1);
        for(i = 0; i < n; ++i)
            if(parent[i] != -1)
                edges[parent[i]].push_back(i);
        dfs(0, parent, value);
        return count[0];
    }
    void dfs(int id, vector<int>& parent, vector<int>& value)
    {
        for(int next : edges[id])
        {
            dfs(next, parent, value);
        }
        if(value[id]==0)
            count[id] = 0;
        if(parent[id] != -1)
        {
            value[parent[id]] += value[id];
            count[parent[id]] += count[id];
        }
    }
};