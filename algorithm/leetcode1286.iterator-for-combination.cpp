class CombinationIterator {
	vector<string> ans;
	string path;
    int id = 0;
public:
    CombinationIterator(string characters, int combinationLength){
    	dfs(characters, combinationLength, 0);
    }
    void dfs(string &s, int n, int idx)
    {
    	if(path.size() == n)
    	{
    		ans.push_back(path);
    		return;
    	}
    	for(int i = idx; i < s.size(); ++i)
    	{
    		path.push_back(s[i]);
    		dfs(s, n, i+1);
    		path.pop_back();
    	}
    }
    string next() {
    	return ans[id++];
    }
    
    bool hasNext() {
    	return id < ans.size();
    }
};

class CombinationIterator {
	int bits;
	string s;
	int len;
public:
    CombinationIterator(string characters, int combinationLength) {
    	s = characters;
    	bits = (1<<s.size())-1;
    	len = combinationLength;
    }
    int countOne(int n)
    {
    	int count = 0;
    	while(n)
    	{
    		count++;
    		n = n & (n-1);
    	}
    	return count;
    }
    string next() {
    	while(bits > 0 && countOne(bits) != len)
    		bits--;
    	string t;
    	for(int i = s.size()-1; i >= 0; --i)
    	{
    		if((bits>>i)&1)
    			t += s[s.size()-i-1];
    	}
        bits--;
    	return t;
    }
    
    bool hasNext() {
    	while(bits > 0 && countOne(bits) != len)
    		bits--;
    	return bits > 0;
    }
};