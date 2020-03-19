class MyQueue {
    stack<int> in;
    stack<int> out;
    int v;
public:
    /** Initialize your data structure here. */
    MyQueue() {
        
    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        in.push(x);
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        if(!out.empty())
        {
            v = out.top();
            out.pop();
            return v;
        }
        while(!in.empty())
        {
            out.push(in.top());
            in.pop();
        }
        v = out.top();
        out.pop();
        return v;
    }
    
    /** Get the front element. */
    int peek() {
        if(!out.empty())
        {
            v = out.top();
            return v;
        }
        while(!in.empty())
        {
            out.push(in.top());
            in.pop();
        }
        v = out.top();
        return v;
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return in.empty()&&out.empty();
    }
};