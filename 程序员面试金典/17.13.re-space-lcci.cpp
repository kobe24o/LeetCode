class trie
{
public:
	trie* cur;
	trie* next[26] = {NULL};
	bool isEnd = false;

	void insert(string& s)
	{
		cur = this;
		for(int i = s.size()-1; i >= 0; --i)//反向插入
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
    	if(sentence.empty())
    		return 0;
    	int i, j, n = sentence.size();
        unordered_set<string> s;
    	trie *t = new trie(), *cur;
    	for(auto& d : dictionary)
    		t->insert(d);//字典插入trie树
        vector<int> dp(n,INT_MAX);
        for(i = 0; i < n; ++i)
        {
            dp[i] = i+1;
            cur = t;
            for(j = i; j >= 0; --j)//从i处向前在trie树中查找单词
            {	
                if(cur->next[sentence[j]-'a'])//下一个字符存在
                {
                	if(cur->next[sentence[j]-'a']->isEnd)//且是结束位置
                    {
                    	if(j > 0)
                    		dp[i] = min(dp[i], dp[j-1]);
                    	else
                    		dp[i] = 0;
                    }
                    else//不是结束位置，不匹配
                    {
                    	if(j > 0)
                    		dp[i] = min(dp[i], dp[j-1]+i-j+1);
                    	else
                    		dp[i] = min(dp[i], i-j+1);
                    }
                }
                else//下一个字符不存在，可以结束了
                {
                    if(j > 0)
                    	dp[i] = min(dp[i], dp[j-1]+i-j+1);
                    else
                        dp[i] = min(dp[i], i-j+1);
                    break;
                }
                if(dp[i]==0)	break;
                cur = cur->next[sentence[j]-'a'];
            }
        }
        return dp[n-1];
    }
};


class Solution {
public:
    int respace(vector<string>& dictionary, string sentence) {
        if(sentence.empty())
            return 0;
    	int i, j, n = sentence.size();
        unordered_set<string> s;
        vector<int> dp(n,INT_MAX);
    	for(auto& d : dictionary)
    		s.insert(d);
        for(i = 0; i < n; ++i)
        {
            dp[i] = i+1;
            if(s.count(sentence.substr(0,i+1)))
            {
                dp[i] = 0;
                continue;
            }
            for(j = i; j > 0; --j)
            {
                if(s.count(sentence.substr(j,i-j+1)))
                    dp[i] = min(dp[i], dp[j-1]);
                else
                    dp[i] = min(dp[i], dp[j-1]+i-j+1);
                if(dp[i]==0)
                    break;
            }
        }
        return dp[n-1];
    }
};