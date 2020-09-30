class Solution {
public:
    bool canReorderDoubled(vector<int>& A) {
        map<int,int> m;
        for(int a : A)
            m[a]++;
        int count = 0, a, c;
        for(auto it = m.begin(); it != m.end(); ++it)
        {
            a = it->first;
            if(it->second == 0)
                continue;
            if(a < 0)
            {
                if(a&1)
                    return false;
                m[a/2] -= m[a];
                if(m[a/2] < 0)
                    return false;
            }
            else if(a == 0)
            {
                if(m[a]&1)
                    return false;
            }
            else // (a > 0)
            {
                m[2*a] -= m[a];
                if(m[2*a] < 0)
                    return false;
            }
        }
        return true;
    }
};