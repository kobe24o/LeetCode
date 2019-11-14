class Trie
{
public:
	bool isWord;
	Trie* next[26] = {NULL};
	Trie():isWord(false){}	
};

class Solution {
	string ans;
public:
    string longestWord(vector<string>& words) {
    	Trie *root = new Trie();
    	Trie *cur;
       	for(string str : words)
       	{
       		cur = root;
       		for(char ch : str)
       		{
       			if(cur->next[ch-'a'] == NULL)
       				cur->next[ch-'a'] = new Trie();
       			cur = cur->next[ch-'a'];
       		}
       		cur->isWord = true;
       	}
       	string temp;
       	cur = root;
       	int i, j;
       	for(i = 0; i < 26; ++i)
       	{
       		temp = "";
       		if(cur->next[i] && cur->next[i]->isWord)	
       			dfs(cur->next[i], temp, i);
       	}
       	return ans;
    }

    void dfs(Trie* root, string temp, int i)
    {
    	if(!root)
    		return;
    	if(root->isWord)
    	{
    		temp.push_back(i+'a');
    		if(temp.size() > ans.size())
       			ans = temp;
    		for(int j = 0; j < 26; ++j)
    			dfs(root->next[j],temp,j);
    		temp.pop_back();
    	}
    }
};