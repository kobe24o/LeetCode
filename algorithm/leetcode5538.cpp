class Solution {
    vector<int> ans;
    vector<vector<int>> g;//图
    unordered_set<int> sub;//子节点集
    int N;
public:
    vector<int> countSubgraphsForEachDiameter(int n, vector<vector<int>>& edges) {
        N = n;
        ans = vector<int> (n-1, 0);
        g.resize(n);
        for(auto& e : edges)
        {
            g[e[0]-1].push_back(e[1]-1);
            g[e[1]-1].push_back(e[0]-1);
        }
        dfs(0);
        return ans;
    }
    void dfs(int i)
    {
        if(i == N)
        {
            if(sub.size() <= 1)
                return;//题意至少需要两个点
            int d = calculateD();
            if(d != -1)
                ans[d-1]++;
            return;
        }
        dfs(i+1);//当前点不选
        sub.insert(i);
        dfs(i+1);//当前点选
        sub.erase(i);
    }
    int calculateD()//判断联通，以及最大直径
    {
        int last = bfs(*sub.begin(), true);//以任意一点开始bfs
        if(last == -1)//图不连通，返回
            return -1;
        return bfs(last, false);//以last点开始bfs求最大直径
    }
    int bfs(int id, bool option)
    {
        int count = 0, total = sub.size(), last, size, step = 0;
        unordered_set<int> unvis(sub);
        queue<int> q;
        q.push(id);
        unvis.erase(id);
        while(!q.empty())
        {
            size = q.size();
            while(size--)
            {
                last = id = q.front();
                q.pop();
                count++;
                for(int nt : g[id])
                {
                    if(unvis.count(nt))
                    {
                        unvis.erase(nt);
                        q.push(nt);
                    }
                }
            }
            step++;
        }
        if(option == true)
        {
            if(count != total)
                return -1;//不连通
            return last;//最后一个点
        }
        else
        {
            return step-1;
        }
    }
};