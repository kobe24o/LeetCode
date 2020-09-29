class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> outdegree(n, 0);//出度
        vector<int> ans;
        queue<int> q;
        for(int i = 0; i < n; i++) 
        {
            outdegree[i] = graph[i].size();
            if(outdegree[i]==0)//出度为0的是可以到达的终点
                q.push(i);
        }
        vector<vector<int>> rg(n);
        for(int i = 0; i < n; i++)
        {
            for(int j : graph[i])
                rg[j].push_back(i);//建立逆向图
        }
        while(!q.empty())
        {
            int id = q.front();
            q.pop();
            for(auto nt : rg[id])//逆向图
            {
                if(--outdegree[nt] == 0)
                    q.push(nt);
            }
        }
        for(int i = 0; i < n; ++i)
            if(outdegree[i]==0)
                ans.push_back(i);
        return ans;
    }
};