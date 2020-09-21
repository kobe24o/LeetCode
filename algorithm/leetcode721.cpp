class dsu
{
public:
    unordered_map<string,string> f;
    dsu(vector<vector<string>>& accounts)
    {
        for(int i = 0; i < accounts.size(); ++i)
        {
            for(int j = 1; j < accounts[i].size(); ++j)
            {
                if(!f.count(accounts[i][j]))
                    f[accounts[i][j]] = accounts[i][1];
                        //以第一个邮件作为代表
                else
                    merge(accounts[i][j], accounts[i][1]);
                    //有邮件出现过，合并该邮件和当前邮件代表
            }
        }
    }
    void merge(string& a, string& b)
    {
        string fa = find(a), fb = find(b);
        f[fa] = fb;
    }
    string find(string &a)
    {
        if(f[a] == a)
            return a;
        return f[a] = find(f[a]);
    }
};
class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        unordered_map<string, string> m;
        for(int i = 0; i < accounts.size(); ++i)
        {
            m[accounts[i][1]] = accounts[i][0];
            //邮件代表，归属的人名
        }
        dsu u(accounts);
        unordered_map<string, vector<string>> ans;
        string mail, name, tpmail;
        for(auto it = u.f.begin(); it != u.f.end(); ++it)
        {   
            mail = it->first;
            tpmail = u.find(mail);//邮件代表tpmail
            ans[tpmail].push_back(mail);
        }
        vector<vector<string>> res(ans.size());
        int i = 0;
        for(auto it = ans.begin(); it != ans.end(); ++it, i++)
        {
            res[i] = it->second;//邮件列表
            sort(res[i].begin(), res[i].end());//排序
            res[i].insert(res[i].begin(), m[it->first]);//插入人名
        }
        return res;
    }
};