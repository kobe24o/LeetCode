#include<memory.h>
#include<string>
#include<iostream>
using namespace std;
class TrieNode
{
public:
	char ch;
	TrieNode *next[26];
	bool isEnd;
	TrieNode(char c = '/'):ch(c),isEnd(false) 
	{
		memset(next, 0, sizeof(TrieNode*)*26);
	}
};
class Trie
{
public:
	TrieNode *root;
	Trie()
	{
		root = new TrieNode();
	}
	~Trie()
	{
		destroy(root);
	}
	void destroy(TrieNode *root)
	{
		if(root == NULL)
			return;
		for(int i = 0; i < 26; i++)
			destroy(root->next[i]);
		delete root;
	}
	void insert(string str)
	{
		TrieNode *cur = root;
		for(char s:str)
		{
			if(cur->next[s-'a'] == NULL)
				cur->next[s-'a'] = new TrieNode(s);
			cur = cur->next[s-'a'];
		}
		cur->isEnd = true;
	}
};
class WordDictionary {
	Trie tree;
public:
    /** Initialize your data structure here. */
    WordDictionary() {
        
    }
    
    /** Adds a word into the data structure. */
    void addWord(string word) {
        tree.insert(word);
    }
    
    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word) {
    	TrieNode *cur = tree.root;
    	bool found = false;
    	for(int i = 0; i < 26; ++i)
    	{
	    	find(word,cur->next[i],0,found);
	    }
    	return found;
    }
    void find(string &word, TrieNode *root, int idx, bool &found)
    {
    	if(found || !root)
    		return;
    	if(idx == word.size()-1)
    	{
    		if(root->isEnd)
    			if(word[idx] == '.' || word[idx] == root->ch)
    				found = true;
    		return;
    	}
    	if((word[idx] != '.'&&root->ch == word[idx])||word[idx] == '.')
    	{	
            for(int i = 0; i < 26; ++i)
            {
                find(word,root->next[i],idx+1,found);
            }
    	}
    }
};
int main()
{
	WordDictionary s;
	s.addWord("bad");
	s.addWord("dad");
	s.addWord("mad");
	cout << s.search("pad") << endl; 
	cout << s.search("bad") << endl;
	cout << s.search(".ad") << endl;
	cout << s.search("b..") << endl;
	system("pause");
	return 0;
}