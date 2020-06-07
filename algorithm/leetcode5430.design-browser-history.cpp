class BrowserHistory {
    stack<string> bk, ft;
    string cur, ans;
public:
    BrowserHistory(string homepage) {
    	cur = homepage;
    }
    
    void visit(string url) {
    	while(!ft.empty())
    		ft.pop();
    	bk.push(cur);
    	cur = url;
    }
    
    string back(int steps) {
    	ft.push(cur);
    	while(--steps && !bk.empty())
    	{
    		ft.push(bk.top());
    		bk.pop();
    	}
    	if(!bk.empty())
    	{
    		cur = bk.top();
    		bk.pop();
    	}
    	else
    	{
    		cur = ft.top();
    		ft.pop();
    	}
    	return cur;
    }
    
    string forward(int steps) {
    	bk.push(cur);
    	while(--steps && !ft.empty())
    	{
    		bk.push(ft.top());
    		ft.pop();
    	}
    	if(!ft.empty())
    	{
    		cur = ft.top();
    		ft.pop();
    	}
    	else
    	{
    		cur = bk.top();
    		bk.pop();
    	}
    	return cur;
    }
};