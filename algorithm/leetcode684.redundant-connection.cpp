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
	int find(int a)
	{
		if(f[a] == a) return a;
		return f[a] = find(f[a]);
	}
};
class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        dsu u(edges.size());
        int x, y;
        for(auto& e : edges)
        {
        	if(u.find(e[0]) != u.find(e[1]))
        	{
        		u.merge(e[0], e[1]);
        	}
        	else
        		x = e[0], y = e[1];
        }
        return {x,y};
    }
};