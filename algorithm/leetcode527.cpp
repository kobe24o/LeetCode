class trie
{
public:
    trie* next[26] = {NULL};
    int freq = 0;
    void insert(string& s)
    {
        trie* cur = this;
        for(int i = 0; i < s.size(); i++)
        {
            if(!cur->next[s[i]-'a'])
                cur->next[s[i]-'a'] = new trie();
            cur = cur->next[s[i]-'a'];
            cur->freq++;
        }
    }
};
class Solution {
public:
    vector<string> wordsAbbreviation(vector<string>& dict) {
        unordered_map<string, vector<string>> group;
        unordered_map<string, int> w_id;
        for(int i = 0; i < dict.size(); ++i)
        {
            string g = dict[i][0]+to_string(dict[i].size())+dict[i].back();
            group[g].push_back(dict[i]);
            //按首尾字符+长度信息给字符串分组
            w_id[dict[i]] = i;
        }
        vector<string> ans(dict.size());
        for(auto& strs : group)
        {
            trie* t = new trie(), *cur = t;
            for(auto& s : strs.second)
                t->insert(s);
            for(auto& s : strs.second)
            {
                cur = t;
                string temp;//缩写
                for(int i = 0; i < s.size(); i++)
                {
                    if(cur->next[s[i]-'a']->freq == 1)//自己独有的字符
                    {
                        int count = s.size()-i-2;
                        if(count >= 2)
                            temp += s[i]+to_string(count)+s.back();
                        else
                            temp = s;
                        break;
                    }
                    else
                        temp += s[i];
                    cur = cur->next[s[i]-'a'];
                }
                ans[w_id[s]] = temp;
            }   
        }
        return ans;
    }
};