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
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
        int N = edges.size();
        vector<int> indegree(N+1, 0);
        int node = -1;
        for(auto e : edges)
        {
        	indegree[e[1]]++;
        	if(indegree[e[1]] > 1)
        		node = e[1];
        }
        dsu u(N);
        int x, y;
        vector<vector<int>> E;
        for(auto e : edges)
        {
        	if(node == e[1])//边指向node，先跳过
        	{
        		E.push_back(e);
        		continue;
        	}
        	if(u.find(e[0]) != u.find(e[1]))//两个没有连接
        		u.merge(e[0], e[1]);//把边连接起来
        	else//已经连接了,有环
        		x = e[0], y = e[1];//记录下来
        }
        for(auto e : E)
        {
        	if(u.find(e[0]) != u.find(e[1]))//两个没有连接
        		u.merge(e[0], e[1]);//把边连接起来
        	else//已经连接了,有环
        		x = e[0], y = e[1];//记录下来
        }
        return {x, y};
    }
};