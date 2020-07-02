class MovingAverage {
	queue<int> q;
	int sum = 0;
    int cap;
public:
    /** Initialize your data structure here. */
    MovingAverage(int size) {
    	cap = size;
    }
    
    double next(int val) {
    	sum += val;
        q.push(val);
    	if(q.size() > cap)
    	{
    		sum -= q.front();
    		q.pop();
    	}
    	return sum/double(q.size());
    }
};