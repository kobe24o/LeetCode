class dsu
{
    vector<int> f;
public:
    dsu(int n)
    {
        f.resize(n);
        for(int i = 0; i < n; ++i)
            f[i] = i;
    }
    void merge(int a, int b)
    {
        int fa = find(a);
        int fb = find(b);
        f[fa] = fb;
    }
    int find(int a)
    {
        int origin = a;
        while(a != f[a])
            a = f[a];
        return f[origin] = a;
    }
};
class Solution {
    unordered_map<string, int> w_id;//单词 id映射
    unordered_map<int, string> id_w;//id 单词
    unordered_map<int, vector<string>> f_words;//近义词代表id, 近义词集合
    vector<string> ans;//答案
public:
    vector<string> generateSentences(vector<vector<string>>& synonyms, string text) {
        int i = 0;
        for(auto& s : synonyms)
        {
            if(!w_id.count(s[0]))
            {
                w_id[s[0]] = i;
                id_w[i++] = s[0];
            }
            if(!w_id.count(s[1]))
            {
                w_id[s[1]] = i;
                id_w[i++] = s[1];
            }
        }
        int n = w_id.size(), i1, i2, f;
        //并查集找集合
        dsu u(n);
        for(auto& s : synonyms)
        {
            i1 = w_id[s[0]];
            i2 = w_id[s[1]];
            u.merge(i1, i2);//近义词合并
        }

        for(i = 0; i  < n; ++i)
        {
            f = u.find(i);//近义词代表的id
            f_words[f].push_back(id_w[i]);//加入集合
        }
        for(auto& fw : f_words)
            sort(fw.second.begin(), fw.second.end());//近义词排序
        vector<string> sentenceWords;//获取句子里的单词
        string w;
        for(int i = 0; i < text.size(); ++i)
        {
            if(text[i] == ' ' || i == text.size()-1)
            {
                if(i == text.size()-1) 
                    w += text[i];
                sentenceWords.push_back(w);
                w = "";
            }
            else
                w += text[i];
        }
        string path;
        bt(sentenceWords, 0, path, u);//回溯生成句子
        return ans;
    }
    void bt(vector<string>& sentenceWords, int i, string& path, dsu& u)
    {
        if(i == sentenceWords.size())
        {
            path.pop_back();//空格
            ans.push_back(path);
            return;
        }
        int size = path.size();
        if(!w_id.count(sentenceWords[i]))
        {   //没有近义词
            path += sentenceWords[i]+" ";
            bt(sentenceWords, i+1, path, u);
            path.resize(size);//回溯
        }
        else
        {
            int f = u.find(w_id[sentenceWords[i]]);
            //有近义词，近义词的代表f
            for(int j = 0; j < f_words[f].size(); ++j)//遍历近义词集合
            {
                path += f_words[f][j]+" ";
                bt(sentenceWords, i+1, path, u);
                path.resize(size);//回溯
            }
        }
    }
};