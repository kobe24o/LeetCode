class FrontMiddleBackQueue {
    deque<int> q1, q2;
    int v, ans;
public:
    FrontMiddleBackQueue() {

    }
    bool sameLen()
    {
        return q1.size() == q2.size();
    }
    
    void pushFront(int val) {
        if(q1.empty())
        {
            q1.push_front(val);
            return;
        }
        if(sameLen())
            q1.push_front(val);
        else
        {
            q1.push_front(val);
            v = q1.back();
            q1.pop_back();
            q2.push_front(v);
        }
    }
    
    void pushMiddle(int val) {
        if(q1.empty())
        {
            q1.push_front(val);
            return;
        }
        if(sameLen())
        {
            q1.push_back(val);
        }
        else
        {
            v = q1.back();
            q1.pop_back();
            q2.push_front(v);
            q1.push_back(val);
        }
    }
    
    void pushBack(int val) {
        if(q1.empty())
        {
            q1.push_front(val);
            return;
        }
        if(sameLen())
        {
            q2.push_back(val);
            v = q2.front();
            q2.pop_front();
            q1.push_back(v);
        }
        else
        {
            q2.push_back(val);
        }
    }
    
    int popFront() {
        if(q1.empty())
            return -1;
        if(sameLen())
        {
            ans = q1.front();
            q1.pop_front();
            v = q2.front();
            q2.pop_front();
            q1.push_back(v);
        }
        else
        {
            ans = q1.front();
            q1.pop_front();
        }
        return ans;
    }
    
    int popMiddle() {
        if(q1.empty())
            return -1;
        ans = q1.back();
        q1.pop_back();
        if(!sameLen() && !q2.empty())
        {
            v = q2.front();
            q2.pop_front();
            q1.push_back(v);
        }
        return ans;
    }
    
    int popBack() {
        if(q1.empty())
            return -1;
        if(sameLen())
        {
            ans = q2.back();
            q2.pop_back();
        }
        else
        {
            if(!q2.empty())
            {
                ans = q2.back();
                q2.pop_back();
                v = q1.back();
                q1.pop_back();
                q2.push_front(v);
            }
            else
            {
                ans = q1.back();
                q1.pop_back();
            }
        }
        return ans;
    }
};