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
};
class Solution {
public:
    string smallestEquivalentString(string A, string B, string S) {
    	dsu u(26);
    	for(int i = 0; i < A.size(); ++i)
    	{
    		u.merge(A[i]-'a', B[i]-'a');
    	}
        unordered_map<int, set<int>> m;
        for(int i = 0; i < 26; ++i)
            m[u.find(i)].insert(i);
        for(int i = 0; i < 26; ++i)
        	u.f[i] = *m[u.f[i]].begin();
    	for(int i = 0; i < S.size(); ++i)
    		S[i] = u.find(S[i]-'a')+'a';
    	return S;
    }
};


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
        if(fa > fb)//字母小的当代表
		    f[fa] = fb;
        else
            f[fb] = fa;
	}
	int find(int a)
	{
		int origin = a;
		while(a != f[a])
			a = f[a];
		return f[origin] = a;
	}
};
class Solution {
public:
    string smallestEquivalentString(string A, string B, string S) {
    	dsu u(26);
    	for(int i = 0; i < A.size(); ++i)
    	{
    		u.merge(A[i]-'a', B[i]-'a');
    	}
    	for(int i = 0; i < S.size(); ++i)
    		S[i] = u.find(S[i]-'a')+'a';
    	return S;
    }
};