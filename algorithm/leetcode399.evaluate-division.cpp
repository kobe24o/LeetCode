class Solution {
    unordered_map<string,unordered_map<string,double>> m;//图的矩阵表示
    unordered_set<string> visited;
    vector<double> ans;
    bool found;
    int idx = 0;
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        for(int i = 0; i < equations.size(); ++i)
        {
            m[equations[i][0]][equations[i][1]] = values[i];//正向
            m[equations[i][1]][equations[i][0]] = 1.0/values[i];//反向
        }
        ans.resize(queries.size());
        for(int i = 0; i < queries.size(); ++i)
        {
            if(queries[i][0] == queries[i][1])//分子分母一样
            {
                if(m.count(queries[i][0]))
                    ans[idx++] = 1.0;
                else
                    ans[idx++] = -1.0;
                continue;
            }
            else if(m.count(queries[i][0]) && m[queries[i][0]].count(queries[i][1]))
            {
                ans[idx++] = m[queries[i][0]][queries[i][1]];//存在通路，直接读取
                continue;
            }
            found = false;
            visited.insert(queries[i][0]);//访问标记
            dfs(queries[i][0], queries[i][0], queries[i][1], 1.0);
            if(!found)
                ans[idx++] = -1.0;
            visited.erase(queries[i][0]);//回溯
        }
        return ans;
    }

    void dfs(string& from, string mid, string &to, double v)
    {
        if(found)
            return;
        if(mid == to)//找到了
        {
            ans[idx++] = v;
            m[from][to] = v;//存取起来，方便后面直接读取
            m[to][from] = 1.0/v;
            found = true;
            return;
        }
        for(auto it = m[mid].begin(); it != m[mid].end(); ++it)
        {
            if(!visited.count(it->first))//没访问过到达点
            {
                visited.insert(it->first);//访问标记
                dfs(from, it->first, to, v*m[mid][it->first]);//一路上value相乘
                visited.erase(it->first);//回溯
            }
        }
    }
};