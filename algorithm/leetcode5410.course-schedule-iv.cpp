class Solution {    //超时
public:
    vector<bool> checkIfPrerequisite(int n, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        unordered_map<int,unordered_set<int>> m;
        vector<bool> ans(queries.size());
        for(auto& pre : prerequisites)
            m[pre[0]].insert(pre[1]);
        int idx = 0, tp;
        bool found;
        for(auto& que : queries)
        {
            if(m.count(que[0]) && m[que[0]].count(que[1]))
                ans[idx++] = true;
            else
            {
                vector<bool> vis(n,false);
                vis[que[0]] = true;
                queue<int> q;
                q.push(que[0]);
                found = false;
                while(!q.empty())
                {
                    tp = q.front();
                    if(tp == que[1])
                    {
                        ans[idx++] = true;
                        found = true;
                        break;
                    }
                    m[que[0]].insert(tp);//加速后面查找
                    q.pop();
                    for(auto it = m[tp].begin(); it != m[tp].end(); ++it)
                    {
                        if(!vis[*it])
                        {
                            q.push(*it);
                            vis[*it] = true;
                        }
                    }
                }
                if(!found)
                    ans[idx++] = false;
            }
        }
        return ans;
    }
};

class Solution {
public:
    vector<bool> checkIfPrerequisite(int n, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        vector<vector<bool>> m(n, vector<bool>(n,false));
        for(auto& pre : prerequisites)
            m[pre[0]][pre[1]] = true;
        int i, j, k;
        for(i = 0; i < n; ++i)
        {
            for(j = 0; j < n; ++j)
            {
                for(k = 0; k < n; ++k)
                {
                    if(m[j][i] && m[i][k])
                        m[j][k] = true;
                }
            }
        }
        vector<bool> ans(queries.size());
        i = 0;
        for(auto& q : queries)
        {
            ans[i++] = m[q[0]][q[1]];
        }
        return ans;
    }
};