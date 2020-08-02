class Solution {
public:
    int minimumSemesters(int N, vector<vector<int>>& relations) {
        unordered_map<int,unordered_set<int>> m;
        vector<int> indegree(N+1, 0);
        for(auto& re:relations)
        {
        	indegree[re[1]]++;
        	m[re[0]].insert(re[1]);
        }
        queue<int> q;
        int cur, size, sum = 0, finish = 0;
        for(int i = 1; i <= N; ++i)
        	if(indegree[i] == 0)
        		q.push(i);
        while(!q.empty())
        {
        	size = q.size();
        	while(size--)
        	{
        		cur = q.front();
        		q.pop();
        		finish++;
        		for(auto it = m[cur].begin(); it != m[cur].end(); ++it)
        		{
        			if(--indegree[*it] == 0)
        				q.push(*it);
        		}
        	}
        	sum++;
        }
        return finish==N ? sum : -1;
    }
};