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
		int fx = find(x), fy = find(y);
		if(fx != fy)
            f[fx] = fy;
	}
};
class Solution {
public:
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
    	int n = s.size(), i, fatherid;
    	dsu uni(n);
    	for(i = 0; i < pairs.size(); ++i)
    	{
            if(pairs[i][0] > pairs[i][1])
                swap(pairs[i][0],pairs[i][1]);
            uni.merge(pairs[i][0],pairs[i][1]);
        }
    	unordered_map<int,multiset<char>> m;
    	for(i = 0; i < n; ++i)
    	{
            // fatherid = uni.f[i];//错误解，使用之前必须先压缩一次
    		fatherid = uni.find(i);
    		m[fatherid].insert(s[i]);
    	}
    	for(i = 0; i < n; ++i)
    	{
    		// fatherid = uni.f[i];//这样也行，上面已经压缩
            fatherid = uni.find(i);
    		s[i] = *m[fatherid].begin();
    		m[fatherid].erase(m[fatherid].begin());
    	}
    	return s;
    }
};