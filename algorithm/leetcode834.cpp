class Solution {
	vector<int> ans, son, dp;
	vector<vector<int>> g;
public:
    vector<int> sumOfDistancesInTree(int N, vector<vector<int>>& edges) {
    	ans.resize(N);
    	son.resize(N);
    	dp.resize(N);
    	g.resize(N);
    	for(auto& e : edges)
    	{
    		g[e[0]].push_back(e[1]);
    		g[e[1]].push_back(e[0]);
    	}
    	dfs1(0, -1);
    	dfs2(0, -1);
    	return ans;
    }
    void dfs1(int u, int f)
    {	//求子树包含的节点数量
    	// 第一次dfs 得到的每个节点子树节点到该节点的距离和
    	son[u] = 1;
    	dp[u] = 0;
    	for(auto v : g[u])
    	{
    		if(v == f)
    			continue;
    		dfs1(v, u);
    		dp[u] += dp[v]+son[v];//子节点的距离和 + 边被占用次数
    		son[u] += son[v];
    	}
    }
    void dfs2(int u, int f)
    {
    	ans[u] = dp[u];
    	for(auto v : g[u])
    	{
    		if(v == f)
    			continue;
    		int dpu = dp[u], dpv = dp[v];//记录状态
    		int sonu = son[u], sonv = son[v];
    		dp[u] -= dp[v]+son[v];//跟换根节点为 v ，u 变成子节点
    		son[u] -= son[v];
    		dp[v] += dp[u]+son[u];// v 加上 u 的数据
    		son[v] += son[u];
    		dfs2(v, u);
    		dp[u] = dpu, dp[v] = dpv;//回溯状态
    		son[u] = sonu, son[v] = sonv;
    	}
    }
};