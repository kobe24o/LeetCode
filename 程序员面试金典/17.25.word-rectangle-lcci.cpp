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
    		t->insert(w);//单词插入trie
    		m[w.size()].push_back(w);//单词按长度分组
    		maxlen = max(maxlen, int(w.size()));//最大单词长度
    	}
    	
    	for(auto it = m.rbegin(); it != m.rend(); ++it)
    	{	//反向遍历，从长度大的开始
    		if(maxarea/(it->first) >= maxlen)
    			break;//最长的单词*宽度 都不够大，这组不用找了
    		temp.clear();
    		area = 0;
    		dfs(it->second,maxarea,maxlen,area);
    	}
    	return ans;
    }

    void dfs(vector<string>& wd, int& maxarea, int maxlen, int area)
    {
        if(wd[0].size()*maxlen <= maxarea)//找到的面积到极限了，退出吧
            return;//这个优化必须有，没有会超时
        vector<bool> res;
    	for(int i = 0; i < wd.size(); ++i)
    	{
    		temp.push_back(wd[i]);
            res = isgood(temp);//是否合法
    		if(res[0])//可以往下加单词
    		{
                area = temp.size()*temp[0].size();
                if(res[1] && area > maxarea)//都是结束单词
    			{	//更新最大值
    				maxarea = area;
    				ans = temp;
    			}
    			dfs(wd, maxarea, maxlen, area);
    		}
    		// else//不能有else，有的话 if内的dfs出来，没有回溯
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
		return {true, allend};//可以继续插入、每个列向单词都在字典中
	}
};