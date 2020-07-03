class MaxStack {
    int maxelem = INT_MIN;
    stack<int> s;
    stack<int> temp;
    int v, m;
public:
    /** initialize your data structure here. */
    MaxStack() {

    }
    
    void push(int x) {
        maxelem = max(maxelem, x);
        s.push(x);
        s.push(maxelem);
    }
    
    int pop() {
        s.pop();
        v = s.top();
        s.pop();
        maxelem = s.empty() ? INT_MIN : s.top();
        return v;
    }
    
    int top() {
        m = s.top();
        s.pop();
        v = s.top();
        s.push(m);
        return v;
    }
    
    int peekMax() {
        return s.top();
    }
    
    int popMax() {
        int ans = s.top();
        maxelem = s.top();
        bool flag = true;
        while(flag)
        {
            s.pop();
            if(s.top() != maxelem)
                temp.push(s.top());
            else
                flag = false;
            s.pop();
        }
        maxelem = s.empty() ? INT_MIN : s.top();
        while(!temp.empty())
        {
            v = temp.top();
            temp.pop();
            s.push(v);
            maxelem = max(maxelem, v);
            s.push(maxelem);
        }
        return ans;
    }
};

class MaxStack {
    list<int> l;
    map<int, vector<list<int>::iterator>> m;
public:
    /** initialize your data structure here. */
    MaxStack() {
    }
    
    void push(int x) {
        l.push_front(x);
        m[x].push_back(l.begin());
    }
    
    int pop() {
        int v = l.front();
        m[v].pop_back();
        if(m[v].empty())
            m.erase(v);
        l.pop_front();
        return v;
    }
    
    int top() {
        return l.front();
    }
    
    int peekMax() {
        return m.rbegin()->first;
    }
    
    int popMax() {
        int v = m.rbegin()->first;
        auto it = m[v].back();
        m[v].pop_back();
        if(m[v].empty())
            m.erase(v);
        l.erase(it);
        return v;
    }
};