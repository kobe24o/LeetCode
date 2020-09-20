class Solution {
    int maxs = 1;
    unordered_set<string> set;
public:
    int maxUniqueSplit(string s) {
        dfs(s);
        return maxs;
    }   

    void dfs(string s)
    {
        if(s.size()+set.size() <= maxs)
            return;//剪枝，剩余的肯定不够大
        if(s == "")
        {
            maxs = max(maxs, int(set.size()));
            return;
        }
        int n = s.size();
        for(int len = 1; len <= n; ++len) 
        {
            string tmp = s.substr(0, len);
            string rest = s.substr(len);
            if(set.find(tmp) == set.end())
            {
                set.insert(tmp);
                dfs(rest);
                set.erase(tmp);
            }
        }
    }
};