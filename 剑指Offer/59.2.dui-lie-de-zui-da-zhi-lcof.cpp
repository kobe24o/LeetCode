class MaxQueue {
	int v;
	queue<int> q;
    deque<int> Maxlist;
public:
    MaxQueue() {

    }
    
    int max_value() {
    	if(q.empty())
    		return -1;
    	return Maxlist.front();
    }
    
    void push_back(int value) {
    	q.push(value);
    	while(!Maxlist.empty() && Maxlist.back() < value)
    	{
    		Maxlist.pop_back();
    	}
    	Maxlist.push_back(value);
    }
    
    int pop_front() {
    	if(q.empty())
    		return -1;
    	if(q.front() == Maxlist.front())
    		Maxlist.pop_front();
    	v = q.front();
    	q.pop();
    	return v;
    }
};