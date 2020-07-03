class trie
{
public:
    trie* next[26] = {NULL};
    bool isend =  false;
    int count = 0;
    void insert(string& s)
    {
        trie* cur = this;
        for(int i = 0; i < s.size(); i++)
        {
            if(cur->next[s[i]-'a'] == NULL)
                cur->next[s[i]-'a'] = new trie();
            cur = cur->next[s[i]-'a'];
        }
        cur->count++;
        cur->isend = true;
    }
};
class Solution {
public:
    string boldWords(vector<string>& words, string S) {
    	trie *t = new trie(), *cur;
    	for(auto& w : words)
    		t->insert(w);
    	vector<bool> bold(S.size(), false);
    	int boldl = 0, boldr=-1;//开始加粗的位置l,r
    	for(int i = 0, j; i < S.size(); ++i)
    	{
    		cur = t;
    		boldl = max(boldl, i);
    		j = i;
    		while(j < S.size() && cur && cur->next[S[j]-'a'])
    		{
    			cur = cur->next[S[j]-'a'];
    			if(cur->isend)
    				boldr = j;
    			j++;
    		}
    		while(boldl <= boldr)
    			bold[boldl++] = true;
    	}
    	string ans;
    	for(int i = 0; i < S.size(); ++i)
    	{
    		if((i==0 && bold[i]) || (i>0 && !bold[i-1] && bold[i]))//i起点
    			ans += "<b>";
    		ans += S[i];
    		if((i==S.size()-1 && bold[i]) || (i<S.size()-1 && bold[i] && !bold[i+1]))//i是终点
    			ans += "</b>";
    	}
    	return ans;
    }
};