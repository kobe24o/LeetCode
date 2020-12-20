class dsu{
public:
    vector<int> f;
    dsu(int n)
    {
        f.resize(n);
        for(int i = 0; i < n; ++i)
            f[i] = i;
    }
    void merge(int a, int b)
    {
        int fa = find(a), fb = find(b);
        f[fa] = fb;
    }
    int find(int a)
    {
        if(a == f[a])
            return a;
        return f[a] = find(f[a]);
    }
};
class Solution {
public:
    vector<bool> distanceLimitedPathsExist(int n, vector<vector<int>>& edgeList, vector<vector<int>>& queries) {
        dsu u(n);
        vector<bool> ans(queries.size(), false);
        vector<int> q_id(queries.size());
        iota(q_id.begin(), q_id.end(), 0); //生成 0,1,2,3...
        sort(q_id.begin(), q_id.end(),[&](auto& a, auto& b){
            return queries[a][2] < queries[b][2];//对查询的id排序，距离小的先查询
        });
        sort(edgeList.begin(), edgeList.end(),[&](auto& a, auto& b){
            return a[2] < b[2];//边短的先加入并查集合并
        });
        int j = 0, limit;
        for(int i = 0; i < q_id.size(); ++i)
        {
            limit = queries[q_id[i]][2];
            while(j < edgeList.size() && edgeList[j][2] < limit)//距离满足要求
            {
                u.merge(edgeList[j][0], edgeList[j][1]);//合并两点
                j++;
            }
            if(u.find(queries[q_id[i]][0]) == u.find(queries[q_id[i]][1]))
                ans[q_id[i]] = true;
        }
        return ans;
    }
};