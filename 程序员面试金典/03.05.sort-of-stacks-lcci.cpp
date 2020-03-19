class SortedStack {
    stack<int> s;
    stack<int> temp;
    int nextMin;
public:
    SortedStack() {}
    
    void push(int val) {
        if(isEmpty())
            s.push(val);
        else if(temp.empty())
        {
            if(s.top() < val)//栈顶小
                swap(val,s.top());//把栈顶变成大的
            s.push(val);//在把原来的小栈顶放回
        }
        else //s.empty()
        {
            if(temp.top() < val)
                swap(val,temp.top());
            temp.push(val);
        }
    }
    
    void pop() {
        if(isEmpty())
            return;
        if(temp.empty())
        {
            s.pop();//最小值pop
            while(!s.empty())//倒数据到temp
            {
                nextMin = s.top();
                s.pop();
                if(!temp.empty() && nextMin > temp.top())
                    swap(nextMin, temp.top());
                temp.push(nextMin);
            }
        }
        else //s.empty()
        {
            temp.pop();//最小值
            while(!temp.empty())//倒数据到s
            {
                nextMin = temp.top();
                temp.pop();
                if(!s.empty() && nextMin > s.top())
                    swap(nextMin, s.top());
                s.push(nextMin);
            }
        }
    }
    
    int peek() {
        if(isEmpty())
            return -1;
        if(temp.empty())
            return s.top();
        else //s.empty()
            return temp.top();
    }
    
    bool isEmpty() {
        return s.empty()&&temp.empty();
    }
};