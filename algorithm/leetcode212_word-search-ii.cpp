#include <vector>
#include <memory.h>
#include <string>
using namespace std;
class TrieNode
{
public:
	string str;
	TrieNode *next[26];
	bool isEnd;
	TrieNode():isEnd(false) 
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
	void insert(string word)
	{
		TrieNode *cur = root;
		for(char s:word)
		{
			if(cur->next[s-'a'] == NULL)
				cur->next[s-'a'] = new TrieNode();
			cur = cur->next[s-'a'];
		}
		cur->isEnd = true;
		cur->str = word;
	}
};

class Solution {
	Trie tree;
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) 
    {
        for(auto word : words)
        	tree.insert(word);
        int i, j;
        vector<string> ans;
        for(i = 0; i < board.size(); ++i)
        	for(j = 0; j < board[0].size(); ++j)
        		dfs(board,tree.root,i,j,ans);
        return ans;
    }

    void dfs(vector<vector<char>>& b, TrieNode *cur, int x, int y, vector<string> &ans)
    {
		if(cur->isEnd)//先检查字符是不是，而不是坐标，万一坐标出界，但是当前字符串结尾
    	{
    		cur->isEnd = false;//该单词取出，放入答案，关闭
    		ans.push_back(cur->str);
    		return;
    	}
    	if(x < 0 || x == b.size() || y < 0 || y == b[0].size()) 
    		return;
    	if(b[x][y] == '#' || !cur || (b[x][y] != '#' && cur->next[b[x][y]-'a'] == NULL))
    		return;
    	char ch = b[x][y];
    	cur = cur->next[ch-'a'];
    	b[x][y] = '#';	//标记走过
    	dfs(b,cur,x+1,y,ans);
    	dfs(b,cur,x-1,y,ans);
    	dfs(b,cur,x,y+1,ans);
    	dfs(b,cur,x,y-1,ans);
    	b[x][y] = ch;	//恢复现场
    }
};

int main()
{
	vector<vector<char>> b = {{'o','a','a','n'},{'e','t','a','e'},
							  {'i','h','k','r'},{'i','f','l','v'}};
	vector<string> w = {"oath","pea","eat","rain"};
	Solution s;
	s.findWords(b,w);
}