class Solution {
    unordered_map<int,unordered_set<int>> m;
    vector<int> ans;
public:
    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
        for(auto& e : edges)
        {
            m[e[0]].insert(e[1]);
            m[e[1]].insert(e[0]);
        }
        ans.resize(n);
        vector<bool> vis(n,false);
        dfs(0,labels,vis);
        return ans;
    }
    vector<int> dfs(int root, string& labels,vector<bool> &vis)
    {
        vector<int> count(26,0), temp;
        vis[root] = true;//访问过了
        for(auto it = m[root].begin(); it != m[root].end(); ++it)
        {
            if(vis[*it])
                continue;
            temp = dfs(*it,labels,vis);
            for(int i = 0; i < 26; ++i)
                count[i] += temp[i];//把子树的字符计数更新到本节点
        }
        ans[root] = ++count[labels[root]-'a'];//加上自己的
        return count;//返回字符的计数
    }
};