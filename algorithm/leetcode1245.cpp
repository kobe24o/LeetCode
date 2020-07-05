class Solution {
public:
    int treeDiameter(vector<vector<int>>& edges) {
    	int n = edges.size()+1;
    	unordered_map<int,unordered_map<int,bool>> m;
    	for(auto& e : edges)
    	{
    		m[e[0]][e[1]] = 1;
    		m[e[1]][e[0]] = 1;
    	}
    	int a,cur,size,step = 0;
    	queue<int> q;
    	vector<bool> visited(n,false);
    	q.push(0);
    	visited[0] = true;
    	while(!q.empty())
    	{
			cur = q.front();
			q.pop();
			a = cur;//记录最后到达的点a
			for(auto it = m[cur].begin(); it != m[cur].end(); ++it)
			{
				if(!visited[it->first])
				{
					q.push(it->first);
					visited[it->first] = true;
				}
			}
    	}
    	vector<bool> visited1(n,false);
    	q.push(a);//从a出发，到达的最远的就是最大的路径
    	visited1[a] = true;
    	while(!q.empty())
    	{
    		size = q.size();
    		while(size--)
    		{
    			cur = q.front();
    			q.pop();
				for(auto it = m[cur].begin(); it != m[cur].end(); ++it)
                {
                    if(!visited1[it->first])
                    {
                        q.push(it->first);
                        visited1[it->first] = true;
                    }
                }
    		}
    		step++;
    	}
    	return step-1;
    }
};