class Solution {
	unordered_map<int,unordered_set<int>> m;
	bool ans = true;
public:
    bool possibleBipartition(int N, vector<vector<int>>& dislikes) {
    	if(dislikes.size() <= 2) return true;
    	vector<int> color(N+1, 0);
    	for(auto& d : dislikes)
    	{
    		m[d[0]].insert(d[1]);
    		m[d[1]].insert(d[0]);
    	}
    	for(int i = 1; i <= N; i++)
    	{
    		if(color[i] == 0)
    		{
    			color[i] = 1;
    			dfs(i, 1, color);
    			if(!ans)
    				return false;
    		}
    	}
    	return true;
    }
    void dfs(int id, int col, vector<int> &color)
    {
    	if(!ans) return;
    	int nextcol = col==1 ? 2 : 1;
    	for(auto it = m[id].begin(); it != m[id].end(); it++)
    	{
    		if(color[*it] == col)
    			ans = false;
    		if(color[*it] == 0)
	    	{
	    		color[*it] = nextcol;
	    		dfs(*it, nextcol, color);
	    	}
    	}
    }
};

class Solution {
	unordered_map<int,unordered_set<int>> m;
public:
    bool possibleBipartition(int N, vector<vector<int>>& dislikes) {
    	if(dislikes.size() <= 2) return true;
    	vector<int> color(N+1, 0);
    	for(auto& d : dislikes)
    	{
    		m[d[0]].insert(d[1]);
    		m[d[1]].insert(d[0]);
    	}
        queue<int> q;
        int id, col = 1, nextcol, size;
    	for(int i = 1; i <= N; i++)
    	{
    		if(color[i] == 0)
    		{
    			color[i] = 1;
                col = 1;
    			q.push(i);
                while(!q.empty())
                {
                    size = q.size();
                    nextcol = col==1 ? 2 : 1;
                    while(size--)
                    {
                        id = q.front();
                        q.pop();
                        for(auto it = m[id].begin(); it != m[id].end(); it++)
                        {
                            if(color[*it] == col)
                                return false;
                            if(color[*it] == 0)
                            {
                                color[*it] = nextcol;
                                q.push(*it);
                            }
                        }
                    }
                    col = col==1? 2 : 1;
                }
    		}
    	}
    	return true;
    }
};

class dsu
{
	vector<int> f;
public:
	dsu(int n)
	{
		f.resize(n+1);
		for(int i = 0; i < n+1; ++i)
			f[i] = i;
	}
	void merge(int a, int b)
	{
		int fa = find(a), fb = find(b);
		f[fa] = fb;
	}
	int find(int a)//循环+路径压缩
	{
        int origin = a;
		while(a != f[a])
			a = f[a];
		return f[origin] = a;//路径压缩
	}
};
class Solution {
public:
    bool possibleBipartition(int N, vector<vector<int>>& dislikes) {
    	if(dislikes.size() <= 2) return true;
    	dsu u(2*N+1);
        int a, b, da, db;
        for(auto& d : dislikes)
    	{
    		a = d[0];
            b = d[1];
            da = a+N;//a不喜欢的人的编号
            db = b+N;
            if(u.find(a) == u.find(b))
                return false;
            u.merge(a,db);
            u.merge(b,da);
    	}
        return true;
    }
};