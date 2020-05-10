class Solution {
public:
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
    	unordered_map<int,unordered_set<int>> down;
		unordered_map<int,int> up;
		queue<int> apple;
    	for(vector<int> & e : edges)
    	{
    		down[e[0]].insert(e[1]);
    		up[e[1]] = e[0];
    	}
    	vector<bool> visited(n,false);
    	visited[0] = true;
    	queue<int> q;
    	q.push(0);
    	int tp;
    	while(!q.empty())
    	{
    		tp = q.front();
    		q.pop();
    		if(hasApple[tp])
    			apple.push(tp);
    		if(down.count(tp))
    		{
    			for(int idx : down[tp])
    			{
    				q.push(idx);
    				visited[idx] = true;
    			}
    		}
    	}
    	int s = 0;
    	while(!apple.empty())
    	{
    		tp = apple.front();
    		apple.pop();
    		dfs(tp, up, s);
    	}
    	return 2*s;
    }
    void dfs(int i, unordered_map<int,int>& up, int& s)
    {
    	if(up.count(i))
    	{
    		s++;
    		int to = up[i];
    		up.erase(i);
    		dfs(to,up,s);
    	}
    }
};

class Solution {
public:
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
		unordered_map<int,int> up;//向上走的路径
    	for(vector<int> & e : edges)
    	{
    		up[e[1]] = e[0];
    	}
    	
    	int s = 0;
    	for(int i = 0; i < hasApple.size(); ++i)
    	{
    		if(hasApple[i])
    		    dfs(i, up, s);
    	}
    	return 2*s;
    }
    void dfs(int i, unordered_map<int,int>& up, int& s)
    {
    	if(up.count(i))
    	{
    		s++;
    		int to = up[i];
    		up.erase(i);
    		dfs(to,up,s);
    	}
    }
};