class Solution {
    vector<int> f;
    int uni;
    int find(int a)
    {
        if(a == f[a]) return a;
        return f[a] = find(f[a]);
    }
    void merge(int a, int b)
    {
        int fa = find(a), fb = find(b);
        if(fa != fb)
        {
            f[fa] = fb;
            uni--;
        }
    }
public:
    int numSimilarGroups(vector<string>& strs) {
        int n = strs.size();
        uni = strs.size();
        f.resize(n);
        for(int i = 0; i < n; ++i)
            f[i] = i;
        for(int i = 0; i < n; ++i)
        {
            for(int j = i+1; j < n; ++j)
            {
                if(find(i) != find(j) && similar(strs[i], strs[j]))
                {
                    merge(i, j);
                }
            }
        }
        return uni;
    }
    bool similar(string& a, string& b)
    {
        int diff = 0;
        for(int i = 0; i < a.size(); ++i)
        {
            if(a[i] != b[i])
                diff++;
            if(diff > 2)
                return false;
        }
        return true;
    }
};