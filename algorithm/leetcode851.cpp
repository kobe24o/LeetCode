class Solution {
public:
    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
    	int n = quiet.size();
    	vector<vector<int>> g(n);//有向图,富的指向穷的
    	vector<int> indegree(n, 0);//入度
    	for(auto& r : richer)
    	{
    		g[r[0]].push_back(r[1]);
    		indegree[r[1]]++;
    	}
    	queue<int> q;//点的id
    	vector<int> ans(n, -1);
    	for(int i = 0; i< n; i++)
    		ans[i] = i;//初始化最安静的是自己
    	for(int i = 0; i < n; i++)
    	{
    		if(indegree[i] == 0)
    		{
    			q.push(i);
    			//最富裕的人，入度为0
    		}
    	}
    	while(!q.empty())
    	{
    		int id = q.front();//人的id
    		int q_val = quiet[ans[id]];
    		//到他这为止，最安静的人的安静值
            q.pop();
    		for(auto nt : g[id])//跟他连接的人（比他穷）
    		{
    			if(q_val < quiet[ans[nt]])
    			//比 nt 更安静的人是 ans[nt], 其安静值没有q_val小
    				ans[nt] = ans[id];
    			if(--indegree[nt] == 0)
    				q.push(nt);
    		}
    	}
    	return ans;
    }
};