class Solution {
public:
    bool sequenceReconstruction(vector<int>& org, vector<vector<int>>& seqs) {
        int n = org.size();
        vector<bool> exit(n+1, false);
        vector<vector<int>> g(n+1);
        vector<int> indegree(n+1, 0);
        for(auto& s : seqs)
        {
        	int from = -1;
        	for(int i = 0; i < s.size(); ++i)
        	{
        		if(s[i] <= 0 || s[i] > n) return false;
        		exit[s[i]] = true;
        		if(from != -1)
        		{
        			g[from].push_back(s[i]);
        			indegree[s[i]]++;
        		}
        		from = s[i];
        	}
        }
        queue<int> q;
        for(int i = 1; i <= n; ++i)
        {
        	if(!exit[i]) return false;
        	if(indegree[i]==0)
        		q.push(i);
        }
        if(q.size() != 1) return false;
        int i = 0;
        while(!q.empty())
        {
        	if(q.size() != 1) return false;
        	int cur = q.front();
        	if(cur != org[i++]) return false;
        	q.pop();
        	for(int i = 0; i < g[cur].size(); ++i)
        	{
        		if(--indegree[g[cur][i]] == 0)
        			q.push(g[cur][i]);
        	}
        }
        if(i != n) return false;
        return true;
    }
};