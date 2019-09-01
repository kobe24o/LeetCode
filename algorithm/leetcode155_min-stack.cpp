class MinStack {
    list<int> stk;
    list<int> min;
public:
    /** initialize your data structure here. */
    MinStack() {
    }
    
    void push(int x) {
        if(min.empty()||min.front() >= x)
            min.push_front(x);
        stk.push_front(x);
    }
    
    void pop() {
        if(stk.front()==min.front())
            min.pop_front();
        stk.pop_front();
    }
    
    int top() {
        return stk.front();
    }
    
    int getMin() {
        return min.front();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */

class MinStack {
    list<int> stk;
    int curMin;
public:
    /** initialize your data structure here. */
    MinStack() {
    }
    
    void push(int x) {
        if(stk.empty())
        {
        	curMin = x;
        }
        else
        {
            curMin = stk.front();//之前没有写这句，当数据有pop时，curMin会变
        	if(x < curMin)
        		curMin = x;
        }
        stk.push_front(x);//数据在当前数据下最小值的下面
        stk.push_front(curMin);//最小值在上
    }
    
    void pop() {
        stk.pop_front();
        stk.pop_front();
    }
    
    int top() {
    	int tmp = stk.front();
    	stk.pop_front();
    	int top = stk.front();
    	stk.push_front(tmp);
        return top;
    }
    
    int getMin() {
        return stk.front();
    }
};