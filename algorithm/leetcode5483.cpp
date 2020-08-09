class Solution {
public:
    string makeGood(string s) {
        if(s.size() <= 1)
            return s;
        string ans;
        stack<char> stk;
        for(int i = 0; i < s.size(); ++i)
        {
            if(!stk.empty() && ((s[i]-stk.top()==32)
                                || (stk.top()-s[i]==32)))
                stk.pop();//前后是大小写关系
            else
                stk.push(s[i]);
        }
        while(!stk.empty())
        {
            ans = stk.top()+ans;
            stk.pop();
        }
        return ans;
    }
};