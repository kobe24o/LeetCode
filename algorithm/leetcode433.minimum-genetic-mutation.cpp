class Solution {
public:
    int minMutation(string start, string end, vector<string>& bank) {
    	if(start.size()!=end.size())
    		return -1;
    	unordered_set<string> s;
    	for(string& b : bank)
    		s.insert(b);//同时兼做未访问的集合
    	if(!s.count(end)) return -1;
    	queue<string> q;
    	string cur, temp;
    	int step = 0, n, i, j;
    	char ch[4] = {'A','G','C','T'};
    	q.push(start);
        if(s.count(start))
            s.erase(start);
    	while(!q.empty())
    	{
    		n = q.size();
    		while(n--)
    		{
    			cur = q.front();
    			if(cur == end)
    				return step;
	    		q.pop();
	    		for(i = 0; i < cur.size(); ++i)
	    		{
	    			for(j = 0; j < 4; ++j)
	    			{
	    				temp = cur;
	    				temp[i] = ch[j];
	    				if(s.count(temp))//未访问的
	    				{
	    					q.push(temp);
	    					s.erase(temp);
	    				}
	    			}
	    		}
    		}
    		step++;
    	}
    	return -1;
    }
};