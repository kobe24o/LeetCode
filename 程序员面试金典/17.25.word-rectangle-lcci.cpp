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
	bool find(string& s)
	{
		trie *cur = this;
		for(int i = 0; i < s.size(); ++i)
		{
			if(!cur->next[s[i]-'a'])
				return false;
			cur = cur->next[s[i]-'a'];
		}
		return cur->isEnd;
	}
};
class Solution {
	trie* t;
	vector<string> ans;
    vector<string> temp;
public:
    vector<string> maxRectangle(vector<string>& words) {
    	t = new trie();
    	map<int,vector<string>> m;
    	int maxlen = 0, maxarea = 0, area;
    	for(auto& w : words)
    	{
    		t->insert(w);
    		m[w.size()].push_back(w);
    		maxlen = max(maxlen, int(w.size()));
    	}
    	
    	for(auto it = m.rbegin(); it != m.rend(); ++it)
    	{
    		if(maxarea/(it->first) >= maxlen)
    			break;//最长的单词都不够
    		temp.clear();
    		area = 0;
    		dfs(it->second,0,maxarea,area);
    	}
    	return ans;
    }

    void dfs(vector<string>& wd, int idx, int& maxarea, int area)
    {
    	for(int i = idx; i < wd.size(); ++i)
    	{
    		temp.push_back(wd[i]);
            vector<bool> res = isgood(temp);
    		if(res[0])//可以往下加单词
    		{
                area = temp.size()*temp[0].size();
                if(res[1] && area > maxarea)//都是结束单词
    			{
    				maxarea = area;
    				ans = temp;
    			}
    			dfs(wd, idx, maxarea, area);
    		}
    		else//不能加
    			temp.pop_back();
    	}
    }


    vector<bool> isgood(vector<string>& tp)
	{
		trie *cur;
        bool allend = true;
		int i, j, n = tp[0].size();
		for(j = 0; j < n; ++j)//按列在trie中检查
		{
			cur = t;
			for(i = 0; i < tp.size(); ++i)
			{
				if(!cur->next[tp[i][j]-'a'])
					return {false, false};
				cur = cur->next[tp[i][j]-'a'];
			}
            allend &= cur->isEnd;
		}
		return {true, allend};
	}
};