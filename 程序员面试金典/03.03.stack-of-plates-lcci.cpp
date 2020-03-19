class StackOfPlates {
	vector<stack<int>> vs;
	int n;
	int val;
public:
    StackOfPlates(int cap) {
    	n = cap;
    }
    
    void push(int val) {
    	if(n == 0)
    		return;
    	if(vs.empty() || vs.back().size()==n)
    	{
    		stack<int> s;
    		vs.push_back(s);
    		vs.back().push(val);
    	}
    	else
    		vs.back().push(val);
    }
    
    int pop() {
    	if(!vs.empty())
    	{
    		val = vs.back().top();
    		vs.back().pop();
    		if(vs.back().empty())
    			vs.pop_back();
    		return val;
    	}
    	return -1;
    }
    
    int popAt(int index) {
    	if(index<0 || index >= vs.size())
    		return -1;
    	val = vs[index].top();
    	vs[index].pop();
    	if(vs[index].empty())
    		vs.erase(vs.begin()+index);
    	return val;
    }
};