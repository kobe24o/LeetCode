#include<vector>
#include<string.h>
#include<iostream>
#include<sstream>
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
				cur->next[s-'a'] = new TrieNode(s-'a');
			cur = cur->next[s-'a'];
		}
		cur->isEnd = true;
	}
};
class Solution {
	Trie tree;
public:
    string replaceWords(vector<string>& dict, string sentence) {
        for(string s:dict)
        	tree.insert(s);
        string word, ans, prefix;
        TrieNode *cur = tree.root;
        istringstream in(sentence);
        int i, chIdx;
        while(in >> word)
        {
        	cur = tree.root;
        	prefix = "";
        	for(i = 0; i < word.size(); ++i)
        	{
        		chIdx = word[i]-'a';
        		if(cur->next[chIdx] == NULL)
	        	{
	        		ans += word;
	        		break;
	        	}
	        	else
	        	{
	        		prefix.push_back(word[i]);
	        		if(cur->next[chIdx]->isEnd)
        			{
        				ans += prefix;
        				break;
        			}
                    if(i == word.size()-1)
        				ans += prefix;
	        	}
	        	cur = cur->next[chIdx];
        	}
        	ans.push_back(' ');
        }
        ans.pop_back();
        return ans;
    }
};

int main()
{
	Solution s;
	vector<string> vec = {"cat", "bat", "rat"};
	s.replaceWords(vec,"the cattle was rattled by the battery");
	return 0;
}