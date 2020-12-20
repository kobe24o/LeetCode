class Solution {
public:
    string reformatNumber(string number) {
        string t, ans;
        for(auto c : number)
            if(c!=' ' && c!='-')
                t += c;
        int n = 0;
        for(int i = 0; i < t.size(); i++)
        {
            if(n == 3)
            {
                ans += '-';
                n = 0;
            }
            ans += t[i];
            n++;
        }
        if(t.size()%3 == 1)
        {
            string tail3 = '-' + t.substr(t.size()-2);
            return ans.substr(0,ans.size()-3)+tail3;
        }
        return ans;
    }
};