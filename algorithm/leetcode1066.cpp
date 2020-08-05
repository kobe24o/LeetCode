class Solution {	//超时
	int mindis = INT_MAX;
public:
    int assignBikes(vector<vector<int>>& workers, vector<vector<int>>& bikes) {
        int nw = workers.size(), nb = bikes.size(), i, j;
        vector<vector<int>> dis(nw, vector<int>(nb));
        vector<bool> vis(nb, false);
        for(i = 0; i < nw; ++i)
        	for(j = 0; j < nb; ++j)
        		dis[i][j] = abs(workers[i][0]-bikes[j][0])+ abs(workers[i][1]-bikes[j][1]);
        dfs(workers, bikes, vis, dis, 0, 0);
        return mindis;
    }
    void dfs(vector<vector<int>>& workers, vector<vector<int>>& bikes,
    			vector<bool> &vis, vector<vector<int>> &dis, int idx, int distance)
    {
    	if(idx == workers.size())
    	{
    		mindis = min(mindis, distance);
    		return;
    	}
    	for(int i = 0; i < bikes.size(); ++i)
    	{
    		if(vis[i]) continue;
    		vis[i] = true;
            if(distance < mindis)
    		    dfs(workers, bikes, vis, dis, idx+1, distance+dis[idx][i]);
    		vis[i] = false;
    	}
    }
};