class Solution {
public:
    int minimumJumps(vector<int>& forbidden, int a, int b, int x) {
        int endpos = x+4000;
    	vector<bool> vis(endpos, false);
    	unordered_set<int> fib(forbidden.begin(), forbidden.end());
    	vis[0] = true;
    	queue<pair<int,bool>> q;
    	q.push({0,false});//位置，上一次是向后的吗
    	int step = 0, size;
    	while(!q.empty()) 
    	{
    		size = q.size();
    		while(size--)
    		{
    			int p = q.front().first;
                bool back = q.front().second;
    			if(p == x)
    				return step;
    			q.pop();
    			if(p+a < endpos && !fib.count(p+a) && !vis[p+a])
    			{
    				vis[p+a] = true;
    				q.push({p+a, false});
    			}
    			if(p-b > 0 && !fib.count(p-b) && !vis[p-b] && !back)
    			{
    				// vis[p-b] = true; //不能写
    				q.push({p-b, true});
    			}
    		}
    		step++;
    	}
    	return -1;
    }
};

class Solution {
public:
    int minimumJumps(vector<int>& forbidden, int a, int b, int x) {
        int endpos = x+4000;
    	vector<vector<bool>> vis(endpos, vector<bool>(2,false));
    	unordered_set<int> fib(forbidden.begin(), forbidden.end());
    	vis[0][0] = vis[0][1] = true;
    	queue<pair<int,bool>> q;
    	q.push({0,false});//位置，上一次是向后的吗
    	int step = 0, size;
    	while(!q.empty()) 
    	{
    		size = q.size();
    		while(size--)
    		{
    			int p = q.front().first;
                bool back = q.front().second;
    			if(p == x)
    				return step;
    			q.pop();
    			if(p+a < endpos && !fib.count(p+a) && !vis[p+a][0])
    			{
    				vis[p+a][0] = true;
    				q.push({p+a, false});
    			}
    			if(p-b > 0 && !fib.count(p-b) && !vis[p-b][1] && !back)
    			{
    				vis[p-b][1] = true; 
    				q.push({p-b, true});
    			}
    		}
    		step++;
    	}
    	return -1;
    }
};