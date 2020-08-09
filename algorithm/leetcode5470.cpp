class Solution {
public:
    int minInsertions(string s) {
        int sum = 0, l = 0, r = 0;
        char prev = '-';
        for(int i = 0; i < s.size(); ++i)
        {
            if(s[i] == '(')
            {
                if(2*l < r)
                {
                    sum += (r-2*l)/2 + (((r-2*l)&1) ?  2 : 0);
                    l = r = 0;
                }
                else if(r > 0)
                {
                    sum += 2*l-r;
                    l = r = 0;
                }
                l++;
            }
            else
                r++;
            
            prev = s[i];
        }
        if(2*l >= r)
            sum += 2*l-r;
        else
            sum += (r-2*l)/2 + (((r-2*l)&1) ?  2 : 0);
        return sum;
    }
};