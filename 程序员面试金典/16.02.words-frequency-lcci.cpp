class WordsFrequency {
	unordered_map<string,int> m;
public:
    WordsFrequency(vector<string>& book) {
    	for(auto& s : book)
    		m[s]++;
    }
    
    int get(string word) {
    	return m[word];
    }
};

//------------------------------
class Trie
{
public:
	unordered_map<char,Trie*> next;
	bool isEnd = false;
	int count = 0;

	void insert(string& s)
	{
		Trie *root = this;
		for(char ch : s)
		{
			if(!(root->next).count(ch))
			{
				Trie* node = new Trie();
				root->next.insert(make_pair(ch,node));
			}
			root = root->next[ch];
		}
		root->isEnd = true;
		root->count++;
	}

	int search(string& s)
	{
		Trie * root = this;
		for(char ch : s)
		{
			if(!(root->next).count(ch))
			{
				return 0;
			}
			root = root->next[ch];
		}
		if(root->isEnd)
			return root->count;
		return 0;
	}
};
class WordsFrequency {
	Trie *t;
public:
    WordsFrequency(vector<string>& book) {
    	t = new Trie();
    	for(string& b : book)
    		t->insert(b);
    }
    
    int get(string word) {
    	return t->search(word);
    }
};