typedef pair<vector<int>, int> p_score;
struct cmp
{
    bool operator()(const p_score& a, const p_score& b) const
    {
        return a.second > b.second;//得分小的路径优先
    }
};
class Solution {//超时
public:
    vector<int> mostSimilar(int n, vector<vector<int>>& roads, vector<string>& names, vector<string>& targetPath) {
        vector<vector<int>> g(n);
        unordered_map<int, string> id_name;
        for(int i = 0; i < n; ++i)
            id_name[i] = names[i];
        for(auto& r : roads)
        {
            g[r[0]].push_back(r[1]);
            g[r[1]].push_back(r[0]);
        }
        int len = targetPath.size();
        priority_queue<p_score, vector<p_score>, cmp> q;
        for(int i = 0; i < n; ++i)
        {
            if(id_name[i] == targetPath[0])
                q.push({{i}, 0});
            else
                q.push({{i}, 1});
        }
        vector<int> p;
        while(!q.empty())
        {
            auto t = q.top();
            q.pop();
            p = t.first;
            int scores = t.second;
            int cur = p.back();
            if(p.size()==len)
                break;
            for(int next : g[cur])
            {
                auto newp = p;
                newp.push_back(next);
                auto newscore = scores + (id_name[next]==targetPath[p.size()] ? 0 : 1);
                q.push({newp, newscore});
            }
        }
        return p;
    }
};

class Solution {
public:
    vector<int> mostSimilar(int n, vector<vector<int>>& roads, vector<string>& names, vector<string>& targetPath) {
        vector<vector<int>> g(n);
        unordered_map<int, string> id_name;
        for(int i = 0; i < n; ++i)
            id_name[i] = names[i];
        for(auto& r : roads)
        {
            g[r[0]].push_back(r[1]);
            g[r[1]].push_back(r[0]);
        }
        int len = targetPath.size();
        priority_queue<p_score, vector<p_score>, cmp> q;
        for(int i = 0; i < n; ++i)
        {
            if(id_name[i] == targetPath[0])
                q.push({{i}, 0});
            else
                q.push({{i}, 1});
        }
        vector<int> p;
        while(!q.empty())
        {
            auto t = q.top();
            q.pop();
            p = t.first;
            int scores = t.second;
            int cur = p.back();
            if(p.size()==len)
                break;
            for(int next : g[cur])
            {
                auto newp = p;
                newp.push_back(next);
                auto newscore = scores + (id_name[next]==targetPath[p.size()] ? 0 : 1);
                q.push({newp, newscore});
            }
        }
        return p;
    }
};