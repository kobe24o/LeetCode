class Solution {
public:
    int minDays(int n) {
        unordered_set<int> vis;
    	queue<int> q;
    	q.push(0);
    	int d = 0, size, eat;
    	while(!q.empty())
    	{
    		size = q.size();
    		while(size--)
    		{
    			eat = q.front();
                q.pop();
    			if(eat == n)
    				return d;
                if(!vis.count(eat+1))
    			{
    				q.push(eat+1);
    				vis.insert(eat+1);
    			}
    			if((n-eat)%2 == 0 && !vis.count(eat+(n-eat)/2))
    			{
    				q.push(eat+(n-eat)/2);
    				vis.insert(eat+(n-eat)/2);
    			}
    			if((n-eat)%3 == 0 && !vis.count(eat+(n-eat)/3*2))
    			{
    				q.push(eat+(n-eat)/3*2);//注意先除再乘，避免溢出
    				vis.insert(eat+(n-eat)/3*2);
    			}
    		}
    		d++;
    	}
    	return -1;
    }
};