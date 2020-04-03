class trie
{
public:
	trie* cur;
	trie* next[26] = {NULL};
	bool isEnd = false;

	void insert(string& s)
	{
		cur = this;
		for(int i = 0; i < s.size(); ++i)
		{
			if(cur->next[s[i]-'a'] == NULL)
			{
				cur->next[s[i]-'a'] = new trie();
			}
			cur = cur->next[s[i]-'a'];
		}
		cur->isEnd = true;
	}
	bool find(string& s, int idx=0)
	{
		cur = this;
		for(int i = idx; i < s.size(); ++i)
		{
			if(cur->next[s[i]-'a'] == NULL)
			{
				cur->next[s[i]-'a'] = new trie();
			}
			cur = cur->next[s[i]-'a'];
		}
		cur->isEnd = true;
	}
};

class Solution {
public:
    int respace(vector<string>& dictionary, string sentence) {
    	int i, j, n = sentence.size();
    	trie t;
    	for(auto& s : dictionary)
    		t.insert(s);

    }
};