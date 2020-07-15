class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
    	int n = graph.size();
    	vector<int> color(n, 0);
        for(int i = 0; i < n; ++i)
    	{
    		if(color[i] != 0)
    			continue;
    		queue<int> q;
	    	q.push(i);
	        color[i] = 1;
	    	int curColor = 1, newColor, id, size, k;
	    	while(!q.empty())
	    	{
    			id = q.front();
    			q.pop();
    			curColor = color[id];
                newColor = curColor==1 ? 2 : 1;
    			for(k = 0; k < graph[id].size(); ++k)
    			{
    				if(color[graph[id][k]] == 0)
    				{
    					q.push(graph[id][k]);
                        color[graph[id][k]] = newColor;
    				}
    				else if(color[graph[id][k]] == curColor)
    					return false;
    			}
    		}
    	}
    	return true;
    }
};