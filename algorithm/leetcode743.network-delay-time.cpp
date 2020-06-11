struct cmp
{
	bool operator()(const pair<int,int>& a, const pair<int,int>& b) const
	{
		return a.second > b.second;//小顶堆，时间短的优先
	}
};
class Solution {	//错误解
public:
    int networkDelayTime(vector<vector<int>>& times, int N, int K) {
    	vector<int> cost(N+1,-1);
    	unordered_map<int,unordered_map<int,int>> m;
    	for(auto& t : times)
    		m[t[0]][t[1]] = t[2];
    	cost[K] = 0;
    	priority_queue<pair<int,int>,vector<pair<int,int>>,cmp> q;//小顶堆
    	q.push({K,0});
    	int node, t;
    	while(!q.empty())
    	{
    		node = q.top().first;
    		t = q.top().second;
    		q.pop();
    		for(auto it = m[node].begin(); it != m[node].end(); ++it)
    		{
    			if(cost[it->first] == -1)//没访问过
    			{
    				q.push({it->first, t+it->second});
    				cost[it->first] = t+it->second;
    			}
    		}
    	}
    	int maxt = 0;
    	for(int i = 1; i <= N; ++i)
    	{
    		if(cost[i] == -1)
    			return -1;
    		maxt = max(maxt, cost[i]);
    	}
    	return maxt;
    }
};

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int N, int K) {
    	vector<vector<int>> cost(N+1,vector<int>(N+1,INT_MAX));
    	for(auto& t : times)
    		cost[t[0]][t[1]] = t[2];
    	int i,j,k;
        for(k = 1; k <= N; ++k)
            for(i = 1; i <= N; ++i)
            {
                for(j = 1; j <= N; ++j)
                {
                    if(cost[i][k] != INT_MAX && cost[k][j] != INT_MAX
                        && cost[i][j] > cost[i][k]+cost[k][j])
                    {
                        cost[i][j] = cost[i][k]+cost[k][j];
                    }
                }
            }
    	int maxt = 0;
    	for(i = 1; i <= N; ++i)
    	{
            if(i == K)
                continue;
    		if(cost[K][i] == INT_MAX)
    			return -1;
    		maxt = max(maxt, cost[K][i]);
    	}
    	return maxt;
    }
};