class Solution {
public:
    int minJump(vector<int>& jump) {
    	int i, j, n = jump.size(), t = 0, size,tp;
    	vector<bool> vis(n,false);
    	vis[0] = true;
    	set<int> set;
    	for(i = 0; i < n; ++i)
    		set.insert(i);
    	queue<int> q;
    	q.push(0);
    	set.erase(0);
    	while(!q.empty())
    	{
    		size = q.size();
    		t++;
    		while(size--)
    		{
    			tp = q.front();
    			q.pop();
    			if(tp+jump[tp] >= n)
    				return t;
    			if(set.count(tp+jump[tp]))
    			{
    				q.push(tp+jump[tp]);
    				set.erase(tp+jump[tp]);
    			}
    			auto end = set.upper_bound(tp);
    			for(auto it = set.begin(); it != end; ++it)
    			{
    				q.push(*it);
    				set.erase(it);
    			}
    		}
    	}
    	return t;
    }
};