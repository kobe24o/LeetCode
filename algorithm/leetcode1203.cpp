class Solution {
public:
    vector<int> sortItems(int n, int m, vector<int>& group, vector<vector<int>>& beforeItems) {
        for(int i = 0; i < n; i++)
        {
            if(group[i] == -1)
                group[i] = m++;//无人接管的分配一个虚拟团队号
        }
        vector<vector<int>> itemgraph(n);
        vector<vector<int>> groupgraph(m);
        vector<int> itemIndegree(n, 0);
        vector<int> groupIndegree(m, 0);
        for(int i = 0; i < n; i++)
        {
            for(auto j : beforeItems[i])
            {
                itemgraph[j].push_back(i);//建图
                itemIndegree[i]++;//记录出入度
                if(group[i] != group[j]) // 注意条件
                {	// 团队也建图，记录出入度
                    groupgraph[group[j]].push_back(group[i]);
                    groupIndegree[group[i]]++;
                }
            }
        }
        vector<vector<int>> g_items(m);
        // item 拓扑排序
        queue<int> q;
        for(int i = 0; i < n; i++)
            if(itemIndegree[i] == 0)
                q.push(i);
        int countItem = 0;
        while(!q.empty())
        {
            int i = q.front();
            q.pop();
            countItem++;
            g_items[group[i]].push_back(i);
            //每个item顺序存入自己的团队
            for(auto j : itemgraph[i])
            {
                if(--itemIndegree[j]==0)
                    q.push(j);
            }
        }
        if(countItem != n)
            return {};
        // 团队拓扑排序
        vector<int> g_order;
        for(int i = 0; i < m; i++)
            if(groupIndegree[i] == 0)
                q.push(i);
        int countgroup = 0;
        while(!q.empty())
        {
            int g = q.front();
            q.pop();
            countgroup++;
            g_order.push_back(g);
            for(auto j : groupgraph[g])
            {
                if(--groupIndegree[j]==0)
                    q.push(j);
            }
        }
        if(countgroup != m)
            return {};
        // 写入答案
        vector<int> ans(n);
        int idx = 0;
        for(auto g : g_order)
        {
            for(auto i : g_items[g])
                ans[idx++] = i;
        }
        return ans;
    }
};