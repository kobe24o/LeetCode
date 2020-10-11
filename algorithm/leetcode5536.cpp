class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        vector<int> indegree(n, 0);
        vector<unordered_set<int>> g(n);
        for(auto& r : roads)
        {
            indegree[r[0]]++;
            indegree[r[1]]++;
            g[r[0]].insert(r[1]);
            g[r[1]].insert(r[0]);
        }
        int maxRank = 0;
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(i == j) continue;
                if(g[i].count(j))
                    maxRank = max(maxRank, indegree[i]+indegree[j]-1);
                else
                    maxRank = max(maxRank, indegree[i]+indegree[j]);
            }
        }
        return maxRank;
    }
};