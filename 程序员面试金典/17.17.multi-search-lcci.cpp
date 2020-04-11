class Solution {	//TLE
public:
    vector<vector<int>> multiSearch(string big, vector<string>& smalls) {
    	unordered_map<char,vector<int>> m;
    	int i, j, n = smalls.size();
    	bool found;
    	vector<vector<int>> ans(n);
    	for(i = 0; i < big.size(); ++i)
    		m[big[i]].push_back(i);
    	for(i = 0; i < n; ++i)
    	{
    		if(smalls[i].empty())
    			continue;
    		for(auto idx : m[smalls[i][0]])
    		{
    			found = true;
    			if(big.size()-idx < smalls[i].size())
    				break;
    			for(j = 0; j < smalls[i].size(); ++j)
    			{
    				if(big[idx+j] != smalls[i][j])
    				{
    					found = false;
    					break;
    				}
    			}
    			if(found)
    				ans[i].push_back(idx);
    		}
    	}
    	return ans;
    }
};
//------------Trie
class trie
{
public:
	bool isEnd = false;
	trie* next[26] = {NULL};
	void insert(string& s)
	{
		trie *cur = this;
		for(int i = 0; i < s.size(); ++i)
		{
			if(!cur->next[s[i]-'a'])
				cur->next[s[i]-'a'] = new trie();
			cur = cur->next[s[i]-'a'];
		}
		cur->isEnd = true;
	}
};
class Solution {
public:
    vector<vector<int>> multiSearch(string big, vector<string>& smalls) {
    	trie* t = new trie();
    	unordered_map<string,int> m;
    	int i, j, n = smalls.size();
    	bool found;
    	vector<vector<int>> ans(n);
    	for(i = 0; i < n; ++i)
    		m[smalls[i]] = i;
    	for(i = 0; i < n; ++i)
    		t->insert(smalls[i]);
    	string s;
    	trie* cur;
    	for(i = 0; i < big.size(); ++i)
    	{
    		s = "";
    		cur = t;
    		for(j = i; j < big.size(); ++j)
    		{
    			if(!cur->next[big[j]-'a'])
    				break;
    			s += big[j];
    			cur = cur->next[big[j]-'a'];
    			if(cur->isEnd)
    				ans[m[s]].push_back(i);
    		}
    	}
    	return ans;
    }
};