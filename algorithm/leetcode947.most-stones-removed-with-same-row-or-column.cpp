class dsu
{
    vector<int> f;
public:
    dsu(int n)
    {
        f.resize(n);
        for(int i = 0; i < n; ++i)
            f[i] = i;
    }
    void merge(int a, int b)
    {
        int fa = find(a), fb = find(b);
        f[fa] = fb;
    }
    int find(int a)
    {
        int origin = a;
        while(f[a] != a)
        {
            a = f[a];
        }
        return f[origin] = a;
    }
};
class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        dsu u(20000);
        unordered_set<int> s;
        for(int i = 0; i < stones.size(); ++i)
            u.merge(stones[i][0], stones[i][1]+10000);
        for(int i = 0; i < stones.size(); ++i)
            s.insert(u.find(stones[i][0]));
        return stones.size()-s.size();
    }
};