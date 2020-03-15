class CustomStack {
	int s, v;
	int count = 0;
	deque<int> q;
	deque<int> q1;
public:
    CustomStack(int maxSize) {
        s = maxSize;
    }
    
    void push(int x) {
    	if(count < s)
        {
        	q.push_back(x);
        	count++;
        }
    }
    
    int pop() {
        if(count==0)
        	return -1;
        if(!q.empty())
        {
        	v = q.back();
        	q.pop_back();
        	count--;
        }
        else
        {
        	v = q1.back();
        	q1.pop_back();
        	count--;
        }
        return v;
    }
    
    void increment(int k, int val) {
        int t = min(k, count);
        k = t;
        t = t - q1.size();
        while(t>0)
        {
        	v = q.front();
        	q.pop_front();
        	q1.push_back(v);
            t--;
        }
        t = k;
        while(t>0)
        {
        	v = q1.front()+val;
        	q1.pop_front();
        	q1.push_back(v);
            t--;
        }
        while(k--)
        {
        	q1.push_front(q1.back());
        	q1.pop_back();
        }
    }
};