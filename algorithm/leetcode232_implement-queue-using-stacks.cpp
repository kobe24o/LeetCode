class MyQueue {
    stack<int> inSTK;
    stack<int> outSTK;
public:
    /** Initialize your data structure here. */
    MyQueue() {
        
    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        inSTK.push(x);
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        if(!outSTK.empty())
        {
            int tp = outSTK.top();
            outSTK.pop();
            return tp;
        }
        else
        {
            while(!inSTK.empty())
            {
                outSTK.push(inSTK.top());
                inSTK.pop();
            }
            int tp = outSTK.top();
            outSTK.pop();
            return tp;
        }
    }
    
    /** Get the front element. */
    int peek() {
        if(!outSTK.empty())
            return outSTK.top();
        else
        {
            while(!inSTK.empty())
            {
                outSTK.push(inSTK.top());
                inSTK.pop();
            }
            return outSTK.top();
        }
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return inSTK.empty() && outSTK.empty();
    }
};