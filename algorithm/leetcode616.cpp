class trie
{
public:
    trie* next[128] = {NULL};
    bool isend =  false;
    int count = 0;
    void insert(string& s)
    {
        trie* cur = this;
        for(int i = 0; i < s.size(); i++)
        {
            if(cur->next[s[i]] == NULL)
                cur->next[s[i]] = new trie();
            cur = cur->next[s[i]];
        }
        cur->count++;
        cur->isend = true;
    }
};
class Solution {
public:
    string addBoldTag(string S, vector<string>& words) {
        trie *t = new trie(), *cur;
        for(auto& w : words)
            t->insert(w);
        vector<bool> bold(S.size(), false);//加黑标记
        int boldl = 0, boldr=-1;//开始加粗的位置l,r
        for(int i = 0, j; i < S.size(); ++i)
        {
            cur = t;
            boldl = max(boldl, i);//加黑的地方左端点
            j = i;
            while(j < S.size() && cur && cur->next[S[j]])
            {
                cur = cur->next[S[j]];
                if(cur->isend)
                    boldr = j;//可以加黑的右端点
                j++;
            }
            while(boldl <= boldr)
                bold[boldl++] = true;//标记加黑
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
