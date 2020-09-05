class Solution {
public:
    int numWays(string s) {
        long long n = s.size(), one = 0;
        for(char c : s)
            if(c == '1')
                one++;
        if(one%3)
            return 0;
        long long o1 = 0, o2 = 0;
        long long n1 = 0, n2 = 0, n3=0;
        for(char c : s)
        {
            if(c == '1')
            {
                if(n1 < one/3)
                    n1++;
                else if(n1 == one/3 && n2 < one/3)
                    n2++;
                else if(n1 == one/3 && n2 == one/3)
                    n3++;
            }
            else
            {
                if(n1 == one/3 && n2 == 0)
                    o1++;
                else if(n1 == one/3 && n2 == one/3 && n3 == 0)
                    o2++;
            }
        }
        if(one == 0)
            return ((n-1)*(n-2)/2)%(int)(1e9+7);
        return (o1+1)*(o2+1)%(int)(1e9+7);
    }
};