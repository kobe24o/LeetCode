class Solution {
	unordered_map<int,unordered_set<int>> m;
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
    	if(connections.size() < n-1)
    		return -1;
    	vector<int> visited(n,false);
    	for(auto& c : connections)
    	{
    		m[c[0]].insert(c[1]);
    		m[c[1]].insert(c[0]);
    	}
    	int count = 0, tp;
        queue<int> q;
    	for(int i = 0; i < n; ++i)
    	{
    		if(!visited[i])
    		{
    			count++;
    			visited[i] = true;
    			q.push(i);
    			while(!q.empty())
    			{
    				tp = q.front();
    				q.pop();
    				for(auto c : m[tp])
    				{
    					if(!visited[c])
    					{
    						q.push(c);
    						visited[c] = true;
    					}
    				}
    			}
    		}
    	}
    	return count-1;
    }
};

class Solution {
	unordered_map<int,unordered_set<int>> m;
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
    	if(connections.size() < n-1)
    		return -1;
    	vector<int> visited(n,false);
    	for(auto& c : connections)
    	{
    		m[c[0]].insert(c[1]);
    		m[c[1]].insert(c[0]);
    	}
    	int count = 0;
    	for(int i = 0; i < n; ++i)
    	{
    		if(!visited[i])
    		{
    			count++;
    			visited[i] = true;
    			dfs(i,visited);
    		}
    	}
    	return count-1;
    }
    void dfs(int i, vector<int>& visited)
    {
        for(auto c : m[i])
        {
            if(!visited[c])
            {
                visited[c] = true;
                dfs(c, visited);
            }
        }
    }
};

class dsu
{
public:
    vector<int> f;
    dsu(int n)
    {
        f.resize(n);
        for(int i = 0; i < n; ++i)
            f[i] = i;
    }
    int find(int x)
    {
        if(x == f[x])
            return x;
        return f[x] = find(f[x]);
    }
    void merge(int x, int y)
    {
        int fx = find(x);
        int fy = find(y);
        f[fx] = fy;
    }
    int countuni()
    {
        int count = 0;
        for(int i = 0; i < f.size(); ++i)
        {
            if(i == find(i))
                count++;
        }
        return count;
    }
};

class Solution {
	unordered_map<int,unordered_set<int>> m;
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
    	if(connections.size() < n-1)
    		return -1;
    	dsu uni(n);
        for(auto& c : connections)
            uni.merge(c[0],c[1]);
        return uni.countuni()-1;
    }
};