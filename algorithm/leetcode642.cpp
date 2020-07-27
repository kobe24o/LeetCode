class trie
{
public:
	unordered_map<char, trie*> next;
	string word;
	int freq = 0;
	void insert(string& s, int time)
	{
		trie *cur = this;
		for(int i = 0; i < s.size(); ++i)
		{
			if(!cur->next.count(s[i]))
				cur->next[s[i]] = new trie();
			cur = cur->next[s[i]];
		}
		cur->word = s;
		cur->freq += time;
	}
	void find(trie* cur, vector<pair<int, string>> &freq_wd)
	{
		if(!cur) return;
		if(cur->freq)
			freq_wd.push_back({cur->freq, cur->word});
		for(auto item : cur->next)
			find(item.second, freq_wd);
	}
};
class AutocompleteSystem {
	trie* t, *cur;
	string prefix;
public:
    AutocompleteSystem(vector<string>& sentences, vector<int>& times) {
    	t = new trie();
    	cur = t;
    	for(int i = 0; i < sentences.size(); ++i)
    		t->insert(sentences[i], times[i]);
    }
    
    vector<string> input(char c) {
    	if(c == '#')
    	{
    		t->insert(prefix, 1);
    		prefix = "";
    		cur = t;
    		return {};
    	}
    	else
    	{
    		prefix += c;
    		if(!cur->next.count(c))
				cur->next[c] = new trie();
			cur = cur->next[c];
			vector<pair<int, string>> freq_wd;
			t->find(cur, freq_wd);
			sort(freq_wd.begin(), freq_wd.end(),[&](auto a, auto b){
				if(a.first == b.first)
					return a.second < b.second;
				return a.first > b.first;
			});
			vector<string> ans;
			for(int i = 0; i < min(3, int(freq_wd.size())); ++i)
				ans.push_back(freq_wd[i].second);
			return ans;
    	}
    }
};