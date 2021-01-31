class Solution {
public:
    vector<int> restoreArray(vector<vector<int>>& P) {
        int n = P.size();
        vector<int> ans(n+1, -1);
        unordered_map<int, vector<int>> g;
        unordered_map<int,int> indegree;
        for(auto& p : P)
        {
            g[p[0]].push_back(p[1]);
            g[p[1]].push_back(p[0]);
            indegree[p[0]]++;
            indegree[p[1]]++;
        }
        int start = -1, last = -1;
        for(auto ind : indegree)
        {
            if(ind.second == 1 && start == -1)
                start = ind.first;
            else if(ind.second == 1 && last == -1)
                last = ind.first;
        }
        queue<int> q;
        q.push(start);
        int idx = 0;
        while(!q.empty())
        {
            int t = q.front();
            indegree[t]--;
            ans[idx++] = t;
            q.pop();
            for(int next : g[t])
            {
                if(--indegree[next] == 1)
                    q.push(next);
            }
        }
        ans.back() = last;
        return ans;
    }
};