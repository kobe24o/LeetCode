class MinStack {
    stack<int> s;
    int MIN;
    int tp;
public:
    /** initialize your data structure here. */
    MinStack() {}
    
    void push(int x) {
        if(s.empty())
        {
            s.push(x);
            s.push(x);
        }
        else
        {
            MIN = s.top() < x ? s.top() : x;
            s.push(x);
            s.push(MIN);
        }
    }
    
    void pop() {
        if(!s.empty())
        {
            s.pop();
            s.pop();
        }
    }
    
    int top() {
        if(s.empty())
            return -1;
        MIN = s.top();
        s.pop();
        tp = s.top();
        s.push(MIN);
        return tp;
    }
    
    int min() {
        if(s.empty())
            return -1;
        return s.top();
    }
};