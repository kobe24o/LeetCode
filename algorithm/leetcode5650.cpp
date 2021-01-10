class dsu // 并查集
{
public:
    vector<int> f;
    dsu(int n)
    {
        f.resize(n);
        for(int i = 0; i < n; i++)
            f[i] = i;
    }
    void merge(int a, int b)
    {
        int fa = find(a);
        int fb = find(b);
        f[fa] = fb;
    }
    int find(int a)
    {
        if(a == f[a])
            return a;
        return f[a] = find(f[a]);
    }
};
class Solution {
public:
    int minimumHammingDistance(vector<int>& source, vector<int>& target, vector<vector<int>>& allowedSwaps) {
        int n = source.size();
        dsu u(n);
        for(auto& a : allowedSwaps)
            u.merge(a[0], a[1]);
        int same = 0;
        unordered_map<int,unordered_map<int,int>> m;
        for(int i = 0; i < n; i++)
        {
            int fa = u.find(i);
            m[fa][source[i]]++;
        }
        for(int i = 0; i < n; i++)
        {
            int fa = u.find(i);
            if(m[fa][target[i]] > 0)
            {
                same++;
                m[fa][target[i]]--;
            }
        }
        return n-same;
    }
};
