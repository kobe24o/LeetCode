class CustomStack {
    int n, v, s, count = 0;
    deque<int> q;
public:
    CustomStack(int maxSize) {
        s = maxSize;
    }
    
    void push(int x) {
        if(count < s)
        {
            q.push_back(x);
            count++;
        }
    }
    
    int pop() {
        if(count)
        {
            v = q.back();
            q.pop_back();
            count--;
            return v;
        }
        return -1;
    }
    
    void increment(int k, int val) {
        k = min(count, k);
        n = k;
        while(n--)
        {
            q.push_back(q.front()+val);
            q.pop_front();
        }
        while(k--)
        {
            q.push_front(q.back());
            q.pop_back();
        }
    }
};

class CustomStack {
    int idx = 0, s, count = 0, v, i;
    vector<int> a;
public:
    CustomStack(int maxSize) {
        a.resize(maxSize);
        s = maxSize;
    }
    
    void push(int x) {
        if(count < s)
        {
            a[idx++] = x;
            count++;
        }
    }
    
    int pop() {
        if(count)
        {
            v = a[idx-1];
            idx--;
            count--;
            return v;
        }
        return -1;
    }
    
    void increment(int k, int val) {
        k = min(k, count);
        for(i = 0; i < k; ++i)
            a[i] += val;
    }
};