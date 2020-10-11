class Solution {
    vector<int> ans;
    vector<vector<int>> g;//图
    vector<int> sub;//子节点集
    int N;
public:
    vector<int> countSubgraphsForEachDiameter(int n, vector<vector<int>>& edges) {
        N = n;
        sub = vector<int> (n, 0);
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
            int d = calculateD();
            if(d != -1)
                ans[d-1]++;
            return;
        }
        dfs(i+1);//当前点不选
        sub[i] = 1;//标记节点选中了
        dfs(i+1);//当前点选
        sub[i] = 0;//回溯
    }
    int calculateD()//判断联通，以及最大直径
    {
        int start = -1;
        for(int i = 0; i < N && start == -1; ++i)
            if(sub[i] == 1)
                start = i;
        int last = bfs(start, true);//以任意一点开始bfs
        if(last == -1)//图不连通，返回
            return -1;
        return bfs(last, false);//以last点开始bfs求最大直径
    }
    int bfs(int id, bool option)
    {
        int count = 0, total = accumulate(sub.begin(),sub.end(),0);
        if(total <= 1)
            return -1;// 少于2个点，不满足题意
        int last, size, step = 0;
        vector<int> unvis(sub);
        queue<int> q;
        q.push(id);
        unvis[id] = 0;
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
                    if(unvis[nt])
                    {
                        unvis[nt] = 0;
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