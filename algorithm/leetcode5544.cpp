class Solution {
public:
    string findLexSmallestString(string s, int a, int b) {
    	unordered_set<string> vis;
    	string cur, nt, minstr = s;
    	int i, n = s.size(), bit, pos;
    	vis.insert(s);
    	queue<string> q;
    	q.push(s);
    	while(!q.empty())
    	{
    		cur = q.front();
    		q.pop();
    		if(cur < minstr)
    			minstr = cur;
    		for(int t = 1; t <= 9; t++)
    		{
	    		nt = cur;
	    		for(i = 1; i < n; ++i)
	    		{
	    			bit = (cur[i]-'0'+t*a)%10;
	    			nt[i] = bit;
	    		}
	    		if(!vis.count(nt))
	    		{
	    			vis.insert(nt);
	    			q.push(nt);
	    		}
	    	}
	    	pos = b;
	    	nt = cur;
	    	while(pos != 0)
	    	{
	    		nt = cur.substr(n-b)+cur.substr(0,n-b);
	    		pos = (pos+b)%n;
	    		if(!vis.count(nt))
	    		{
	    			vis.insert(nt);
	    			q.push(nt);
	    		}
	    		cur = nt;
	    	}
    	}
    	return minstr;
    }
};