class Solution {
	vector<int> f;
	void dsu_init(int n)
	{
		f.resize(n);
		for(int i = 0; i < n; i++)
			f[i] = i;
	}
	void merge(int a, int b)
	{
		int fa = find(a), fb = find(b);
		f[fa] = fb;
	}
	int find(int a)
	{
		if(a == f[a])
            return a;
        return f[a] = find(f[a]);
	}

	int remove = 0;
public:
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
    	dsu_init(n);
    	process(edges, 3);
        vector<int> f_copy = f;
    	if(process(edges, 1) != 1)
            return -1;
        f = f_copy;
    	if(process(edges, 2) != 1)
            return -1;
    	return remove;
    }
    int process(vector<vector<int>>& edges, int type)
    {
    	int a, b;
    	for(int i = 0; i < edges.size(); i++)
    	{
    		if(edges[i][0] == type)
    		{
    			a = edges[i][1]-1, b = edges[i][2]-1;
    			if(find(a) != find(b))
    			{
    				merge(a, b);
    			}
    			else
    				remove++;
    		}
    	}
        int count = 0;
        for(int i = 0; i < f.size(); ++i)
        {
            if(find(i) == i)
                count++;
        }
        return count;
    }
};