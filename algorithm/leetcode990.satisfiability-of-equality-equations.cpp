class uni
{
    int f[26];
public:
    uni()
    {
        for(int i = 0; i < 26; ++i)
            f[i] = i;
    }
    int find(int a)
    {
        if(f[a] == a)
            return f[a];
        return f[a] = find(f[a]);
    }
    void merge(int a, int b)
    {
        int fa = find(a);
        int fb = find(b);
        f[fa] = fb;
    }
};
class Solution {
public:
    bool equationsPossible(vector<string>& equations) {
        uni u;
        int a, b, i;
        for(i = 0; i < equations.size(); ++i)
        {
            if(equations[i][1]=='=')
            {
                a = equations[i][0]-'a';
                b = equations[i][3]-'a';
                u.merge(a,b);
            }
        }
        for(i = 0; i < equations.size(); ++i)
        {
            if(equations[i][1]=='!')
            {
                a = equations[i][0]-'a';
                b = equations[i][3]-'a';
                if(u.find(a) == u.find(b))
                    return false;
            }
        }
        return true;
    }
};