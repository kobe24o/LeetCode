class STK//自定义栈
{
public:
	int size;
	int capacity;
	vector<int> data;

	STK(int cap):size(0), capacity(cap) { data.resize(cap);}
	bool isEmpty() const { return size == 0;}
	bool isFull() const { return capacity == size;}
	void push(int val)
	{
		if(!isFull())
			data[size++] = val;
	}

	int pop()
	{
		if(isEmpty())
			return -1;
		return data[--size];
	}
};
class DinnerPlates {
	int cap;
	vector<STK> v;
public:
    DinnerPlates(int capacity) {
        cap = capacity;
    }
    
    void push(int val) {
    	int i = 0;
    	while(i < v.size() && v[i].isFull())
    		i++;
    	if(i < v.size())
    		v[i].push(val);
    	else
    	{
    		v.push_back(STK(cap));
    		v[i].push(val);
    	}
    }
    
    int pop() {
    	int i = v.size()-1;
    	while(i >= 0 && v[i].isEmpty())
    		i--;
    	if(i < 0)
    		return -1;
    	int tp = v[i].pop();
    	return tp;
    }
    
    int popAtStack(int index) {
        if(v.empty() || index >= v.size())
        	return -1;
        return v[index].pop();
    }
};//超时

class STK//自定义栈
{
public:
	int size;
	int capacity;
	vector<int> data;

	STK(int cap):size(0), capacity(cap) { data.resize(cap);}
	bool isEmpty() const { return size == 0;}
	bool isFull() const { return capacity == size;}
	void push(int val)
	{
		if(!isFull())
			data[size++] = val;
	}

	int pop()
	{
		if(isEmpty())
			return -1;
		return data[--size];
	}
};
class DinnerPlates {
	int cap;
	vector<STK> v;
	set<int> s1;//存储没有满的栈的id
	set<int> s2;//存储不为空的栈的id
	int tp;
public:
    DinnerPlates(int capacity) {
        cap = capacity;
    }
    
    void push(int val) {
    	if(!s1.empty())
    	{
    		v[*s1.begin()].push(val);
    		s2.insert(*s1.begin());
    		if(v[*s1.begin()].isFull())
    			s1.erase(s1.begin());
    	}
    	else
    	{
    		v.push_back(STK(cap));
    		v[v.size()-1].push(val);
    		s2.insert(v.size()-1);
    		if(cap != 1)
    			s1.insert(v.size()-1);
    	}

    }
    
    int pop() {
    	if(s2.empty())
    		return -1;
    	tp = v[*(--s2.end())].pop();
    	s1.insert(*(--s2.end()));
    	if(v[*(--s2.end())].isEmpty())
    		s2.erase(*(--s2.end()));
    	return tp;
    }
    
    int popAtStack(int index) {
        if(v.empty() || index >= v.size())
        	return -1;
        tp = v[index].pop();
        if(v[index].isEmpty())
        	s2.erase(index);
        s1.insert(index);
        return tp;
    }
};