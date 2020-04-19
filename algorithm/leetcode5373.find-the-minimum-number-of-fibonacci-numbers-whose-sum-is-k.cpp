class Solution {
public:
    int findMinFibonacciNumbers(int k) {
        set<int> s;
        s.insert(1);
        int a = 1, b =1, fn=1, end = 1000000000;
        while(fn <= end)
        {
            fn = a+b;
            a = b;
            b = fn;
            s.insert(fn);
        }
        int count = 0;
        while(k!=0)
        {
            auto it = s.upper_bound(k);
            k -= *(--it);
            count++;
        }
        return count;
    }
};