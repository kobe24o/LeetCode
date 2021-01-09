class Solution {
public:
    int maximumGain(string s, int x, int y) {
        int ans = 0;
        s.push_back('-');
        int a = 0, b = 0;
        for(int i = 0; i < s.length(); ++i) 
        {
            if(s[i] != 'a' && s[i] != 'b')
            {
                if(a && b)
                    ans += min(x,y)*min(a, b);
                a = b = 0;
            }
            else
            {
                if(s[i] == 'a') a++;
                else if(s[i] == 'b') b++;
                if(a && s[i]=='b' && x >= y)
                    ans += x, a--, b--;
                else if(s[i]=='a' && b && x < y)
                    ans += y, a--,b--;
            }
        }
        return ans;
    }
};