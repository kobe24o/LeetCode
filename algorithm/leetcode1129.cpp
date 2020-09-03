class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& red_edges, vector<vector<int>>& blue_edges) {
    	vector<vector<int>> dis(2, vector<int>(n, INT_MAX));
    	vector<vector<int>> r(n), b(n);
    	for(auto& e : red_edges)
    		r[e[0]].push_back(e[1]);
    	for(auto& e : blue_edges)
    		b[e[0]].push_back(e[1]);
    	bfs(r,b,0,dis);
    	bfs(r,b,1,dis);
    	vector<int> ans(n,-1);
    	for(int i = 0; i < n; ++i)
    	{
    		ans[i] = min(dis[0][i], dis[1][i]);
    		if(ans[i] == INT_MAX)
    			ans[i] = -1;
    	}
    	return ans;
    }

    void bfs(vector<vector<int>>& r, vector<vector<int>>& b, int flag, vector<vector<int>>& dis)
    {
    	int n = r.size(), cur, size, step = 0;
    	vector<vector<bool>> vis(2, vector<bool>(n, false));
    	queue<int> q;
    	q.push(0);
    	vis[flag][0] = true;
    	while(!q.empty())
    	{
    		size = q.size();
    		while(size--)
    		{
    			cur = q.front();
    			dis[flag][cur] = min(dis[flag][cur], step);
    			q.pop();
    			if(flag)
    			{
    				for(auto nt : r[cur])
    				{
    					if(vis[flag][nt])
    						continue;
    					vis[flag][nt] = true;
    					q.push(nt);
    				}
    			}
    			else
    			{
    				for(auto nt : b[cur])
    				{
    					if(vis[flag][nt])
    						continue;
    					vis[flag][nt] = true;
    					q.push(nt);
    				}
    			}
    		}
    		step++;//步数+1
    		flag = !flag;//换地图
    	}
    }
};