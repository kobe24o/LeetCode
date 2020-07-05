class dsu
{
	vector<int> f;
public:
	dsu(int n)
	{
		f.resize(n);
		for(int i = 0; i < n; ++i)
			f[i] = i;
	}
	void merge(int a, int b)
	{
		int fa = find(a), fb = find(b);
		f[fa] = fb;
	}
	int find(int a)
	{
		int origin = a;
		while(a != f[a])
			a = f[a];
		return f[origin] = a;
	}
	int countUni()
	{
		int count = 0;
		for(int i = 0; i < f.size(); ++i)
			if(i == find(i))
				count++;
		return count;
	}
};
class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
    	dsu u(n);
    	for(auto& e : edges)
    		u.merge(e[0], e[1]);
    	return edges.size()+1==n && u.countUni()==1;
    }
};