class Trie//Trie节点
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
       	for(string str : words)//遍历所有单词
       	{
       		cur = root;
       		for(char ch : str)//遍历所有字符
       		{
       			if(cur->next[ch-'a'] == NULL)
       				cur->next[ch-'a'] = new Trie();
       			cur = cur->next[ch-'a'];
       		}
       		cur->isWord = true;//单词结束标志
       	}
       	string temp;
       	cur = root;
       	int i, j;
       	for(i = 0; i < 26; ++i)
       	{
       		temp = "";
       		if(cur->next[i] && cur->next[i]->isWord)//对每个点dfs	
       			dfs(cur->next[i], temp, i);
       	}
       	return ans;
    }

    void dfs(Trie* root, string &temp, int i)
    {
    	if(!root)
    		return;
    	if(root->isWord)//是结束标志，在字典中
    	{
    		temp.push_back(i+'a');//加入该字符
    		if(temp.size() > ans.size())
       			ans = temp;//更新更长的单词
    		for(int j = 0; j < 26; ++j)
    			dfs(root->next[j],temp,j);//dfs下一个字符
    		temp.pop_back();//回溯
    	}
    }
};