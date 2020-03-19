class SortedStack {
    stack<int> s;
    stack<int> temp;
    int minVal = INT_MAX;
    int nextMin;
public:
    SortedStack() {

    }
    
    void push(int val) {
        if(isEmpty())
        {
            s.push(val);
            minVal = val;
        }
        else if(temp.empty())
        {
            if(s.top() >= val)
            {
                s.push(val);
                minVal = val
            }
            else
            {
                minVal = s.top();
                s.pop();
                s.push(val);
                s.push(minVal);
            }
        }
        else //s.empty()
        {
            if(temp.top() >= val)
            {
                temp.push(val);
                minVal = val
            }
            else
            {
                minVal = s.top();
                temp.pop();
                temp.push(val);
                temp.push(minVal);
            }
        }
    }
    
    void pop() {
        if(isEmpty())
            return -1;
        if(temp.empty())
        {
            minVal = s.top();
            s.pop();
            while(!s.empty())
            {
                nextMin = s.top();
                s.pop()
                if(temp.empty() || nextMin <= temp.top())
                    temp.push(nextMin);
                else
                {
                    swap(nextMin, temp.top());
                    temp.push(nextMin);
                }
            }
        }
        else //s.empty()
        {
            minVal = temp.top();
            temp.pop();
            while(!temp.empty())
            {
                nextMin = temp.top();
                temp.pop()
                if(s.empty() || nextMin <= s.top())
                    s.push(nextMin);
                else
                {
                    swap(nextMin, s.top());
                    s.push(nextMin);
                }
            }
        }
    }
    
    int peek() {
        if(isEmpty())
            return -1;
        if(temp.empty())
        {
            minVal = s.top();
            s.pop();
            while(!s.empty())
            {
                nextMin = s.top();
                s.pop()
                if(temp.empty() || nextMin <= temp.top())
                    temp.push(nextMin);
                else
                {
                    swap(nextMin, temp.top());
                    temp.push(nextMin);
                }
            }
            return minVal;
        }
        else //s.empty()
        {
            minVal = temp.top();
            temp.pop();
            while(!temp.empty())
            {
                nextMin = temp.top();
                temp.pop()
                if(s.empty() || nextMin <= s.top())
                    s.push(nextMin);
                else
                {
                    swap(nextMin, s.top());
                    s.push(nextMin);
                }
            }
            return minVal;
        }
    }
    
    bool isEmpty() {
        return s.empty()&&temp.empty();
    }
};