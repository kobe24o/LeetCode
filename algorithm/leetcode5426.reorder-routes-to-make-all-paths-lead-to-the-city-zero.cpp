class Solution {
	int count = 0;
	unordered_map<int,unordered_map<int, bool>> m;
public:
    int minReorder(int n, vector<vector<int>>& connections) {
    	vector<bool> vis(n,false);
    	for(auto& c : connections)
    	{
    		m[c[0]][c[1]] = true;//等于true的需要反转
    		m[c[1]][c[0]] = false;
    	}
    	vis[0] = true;
    	dfs(0, vis);
    	return count;
    }
    void dfs(int i, vector<bool> &vis)
    {
    	for(auto it = m[i].begin(); it != m[i].end(); ++it)
    	{
    		if(!vis[it->first])
    		{
    			if(m[i][it->first])
    				count++;
    			vis[it->first] = true;
    			dfs(it->first, vis);
    		}
    	}
    }
};

class Solution {    
public:
    int minReorder(int n, vector<vector<int>>& connections) {
        int count = 0, id;
        unordered_map<int,unordered_map<int, bool>> m;
        vector<bool> vis(n,false);
        for(auto& c : connections)
        {
            m[c[0]][c[1]] = true;//等于true的需要反转
            m[c[1]][c[0]] = false;
        }
        vis[0] = true;
        queue<int> q;
        q.push(0);
        while(!q.empty())
        {
            id = q.front();
            q.pop();
            for(auto it = m[id].begin(); it != m[id].end(); ++it)
            {
                if(!vis[it->first])
                {
                    if(m[id][it->first])
                        count++;
                    vis[it->first] = true;
                    q.push(it->first);
                }
            }
        }
        return count;
    }
};