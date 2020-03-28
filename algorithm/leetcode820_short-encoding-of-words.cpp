class Solution {
public:
    int minimumLengthEncoding(vector<string>& words) {
    	for(string& w : words)
    		reverse(w);
    	sort(words.begin(), words.end(),[&](string& a, string& b){
    		return a.size() > b.size();
    	});
    	string ans;
    	for(string& w : words)
    	{
            size_t pos = ans.find(w);
    		if(pos == string::npos || ans[pos-1]!='#')
            // ["me" ,"mean"]
    			ans += "#"+w;
    	}
    	return ans.size();
    }

    void reverse(string& s)
    {
    	int i = 0, j = s.size()-1;
    	while(i < j)
    		swap(s[i++],s[j--]);
    }
};
//-----------------------------trie-------------
class Trie
{
public:
	unordered_map<char,Trie*> m;
	bool isEnd = false;

	void rev_insert(string& s)
	{
		Trie* root = this;
		for(int i = s.size()-1; i >= 0; --i)
		{
			if(!(root->m).count(s[i]))
			{
				Trie* node = new Trie();
				root->m.insert(make_pair(s[i],node));
			}
			root = root->m[s[i]];
		}
		root->isEnd = true;
	}
};
class Solution {
	int len = 0;
public:
    int minimumLengthEncoding(vector<string>& words) {
    	Trie *t = new Trie();
    	for(string& w : words)
    		t.rev_insert(w);
    	dfs(t,0);
    	return len;
    }

    void dfs(Trie * root, int count)
    {
    	if(root->m.size()==0)
    	{
    		len += count;
    		return;
    	}
    	for(auto it = root->m.begin(); it != root->m.end(); ++it)
    	{
    		dfs(it->second, count+1);
    	}
    }
};