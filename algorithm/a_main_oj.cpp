#include <bits/stdc++.h>

using namespace std;


struct cmp{
    bool operator()(char a, char b) const
    {
        return a > b;
    }
};
class Solution {
public:
    /**
     * @param currency: a string represents a valid or invalid currency amount
     * @return: return whether the given string is a valid currency
     */
    bool validCurrencyAmount(string &m) {
        // write your code here
        if(m == "" || m[0] == ' ' || m.back() == ' ')
            return false;
        if(m[0] == '-')
            m = m.substr(1);
        if(m.size()>=2 && ((m[0]=='(' && m.back()!=')')
                           || (m[0] !='(' && m.back() == ')')))
            return false;
        if(m[0] == '(' && m.back() == ')')
            m = m.substr(1, m.size()-2);
        if(m[0] != 'D' && m[0] != 'E' && m[0] != 'Y')
            return false;
        if(m[0] == 'D' || m[0] == 'E')
            return check1(m.substr(1));
        else
            return check2(m.substr(1));
    }
    bool check1(string m)
    {
        int len = m.length();
        if(len >= 3 && m[len-3]=='.')
        {
            if(isdigit(m[len-1]) && isdigit(m[len-2]))
                m = m.substr(0, len-3);
            else
                return false;
        }
        int c = 0;
        for(int i = int(m.size())-1; i >= 0; --i)
        {
            if(!isdigit(m[i]) && m[i] != ',')
                return false;
            if(c != 3 && isdigit(m[i]))
                c++;
            else if(c != 3 && !isdigit(m[i]))
                return false;
            else if(c == 3 && m[i] == ',')
                c = 0;
            else if(c == 3 && m[i] != ',')
                return false;
        }
        return len > 0 && m[0] != '0';
    }
    bool check2(string m)
    {
        int len = m.length();
        int c = 0;
        for(int i = int(m.size())-1; i >= 0; --i)
        {
            if(!isdigit(m[i]) && m[i] != ',')
                return false;
            if(c != 3 && isdigit(m[i]))
                c++;
            else if(c != 3 && !isdigit(m[i]))
                return false;
            else if(c == 3 && m[i] == ',')
                c = 0;
            else if(c == 3 && m[i] != ',')
                return false;
        }
        return len > 0 && m[0] != '0';
    }
};
int main()
{

    Solution s;
    vector<int> a = {1,3,4,1,5};
    string s1 = "D450";
    cout << s.validCurrencyAmount(s1) << endl;
    return 0;
}