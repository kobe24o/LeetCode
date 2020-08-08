class dsu
{
	unordered_map<string,string> f;
public:
	dsu(unordered_set<string> &s)
	{
		for(auto& w : s)
    		f[w] = w;//并查集初始化
	}
	void merge(string& a, string& b)
	{
		string fa = find(a);
		string fb = find(b);
		f[fa] = fb;
	}
	string find(string a)
	{
		string origin = a;
		while(a != f[a])
			a = f[a];
		return f[origin] = a;
	}
};
class Solution {
public:
    bool areSentencesSimilarTwo(vector<string>& words1, vector<string>& words2, vector<vector<string>>& pairs) {
    	if(words1.size() != words2.size())
    		return false;
    	unordered_set<string> s;
    	for(auto& p : pairs)
    	{
    		s.insert(p[0]);
    		s.insert(p[1]);
    	}
    	dsu u(s);//并查集
    	for(auto& p : pairs)
    		u.merge(p[0], p[1]);//merge
    	for(int i = 0; i < words1.size(); ++i)
    	{
    		if(words1[i] == words2[i])
    			continue;
    		//并查集find
    		if(u.find(words1[i]) != u.find(words2[i]))
    			return false;
    	}
    	return true;
    }
};