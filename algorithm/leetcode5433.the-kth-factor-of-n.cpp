class Solution {
public:
    int kthFactor(int n, int k) {
        set<int> s;
        for(int i = 1; i <= n; i++) {
            if(n%i==0)
                s.insert(i);
        }
        if(s.size() < k)
            return -1;
        auto it = s.begin();
        while(--k && it != s.end())
        {
            it++;
        }
        return *it;
    }
};