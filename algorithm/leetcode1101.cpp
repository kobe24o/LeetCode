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
		int fa = find(a);
		int fb = find(b);
		f[fa] = fb;
	}
	int find(int a)
	{
		int origin = a;
		while(a != f[a])
			a = f[a];
		return f[origin] = a;
	}
	bool onlyOne()
	{
		int count = 0;
		for(int i = 0; i < f.size(); ++i)
		{
			if(i == find(i))
				count++;
			if(count > 1)
				return false;
		}
		return true;
	}
};
class Solution {
public:
    int earliestAcq(vector<vector<int>>& logs, int N) {
    	sort(logs.begin(), logs.end(),[&](auto a, auto b){
    		return a[0] < b[0];
    	});
    	dsu u(N);
    	for(auto& lg : logs)
    	{
    		u.merge(lg[1], lg[2]);
    		if(u.onlyOne())
    			return lg[0];
    	}
    	return -1;
    }
};