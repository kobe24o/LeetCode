class trie
{
public:
	trie* next[26] = {NULL};
	bool isend =  false;
	int count = 0;
	void insert(string& s)
	{
		trie* cur = this;
		for(int i = 0; i < s.size(); i++)
		{
			if(cur->next[s[i]-'a'] == NULL)
				cur->next[s[i]-'a'] = new trie();
			cur = cur->next[s[i]-'a'];
		}
		cur->count++;
		cur->isend = true;
	}
};
class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
    	trie* t = new trie();
    	for(string& p : products)
    		t->insert(p);
    	vector<vector<string>> ans(searchWord.size());
    	int i = 0, idx = 0, j, n = searchWord.size();
    	string prefix = "";
    	trie* cur;
        bool foundprefix;
    	for(i = 0; i < n; ++i)
    	{
    		prefix += searchWord[i];
    		cur = t;
            foundprefix = true;
    		for(j = 0; j < prefix.size(); ++j)
    		{
    			if(cur->next[prefix[j]-'a'] == NULL)
    			{
                    foundprefix = false;
                    break;
                }
    			cur = cur->next[prefix[j]-'a'];
    		}
            if(foundprefix)
    		    dfs(cur,prefix,ans[i]);
            if(ans[i].empty())
                ans[i] = {};
    	}
    	return ans;
    }

    void dfs(trie* cur, string& str, vector<string>& list)
    {
    	if(list.size() == 3)
    		return;
    	if(!cur) return;
    	if(cur->isend)
    	{
    		int n = cur->count;
    		while(list.size() < 3 && n--)
    			list.push_back(str);
    	}
    	for(int i = 0; i < 26; ++i)
    	{
    		str += i+'a';
    		dfs(cur->next[i],str,list);
    		str.pop_back();
    	}
    }
};

class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        multiset<string> s;
        for(string& p : products)
    		s.insert(p);
        vector<vector<string>> ans(searchWord.size());
        string prefix = "";
        for(int i = 0; i < searchWord.size(); ++i)
    	{
    		prefix += searchWord[i];
            auto start = s.lower_bound(prefix);
    		for(auto it = start; it != s.end() && ans[i].size() < 3; ++it)
    		{
    			if((*it).find(prefix) == 0)
                    ans[i].push_back(*it);
                else
                    break;
    		}
    	}
    	return ans;
    }
};