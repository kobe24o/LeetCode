class Solution {
public:
    string reverseWords(string s) {
        stack<string> stk;
        string str;
        for(int i = 0; i < s.size(); ++i)
        {
            if(s[i] != ' ' && i != s.size()-1)
                str.push_back(s[i]);
            else if(s[i] != ' ' && i == s.size()-1)
            {
                str.push_back(s[i]);
                stk.push(str);
            }
            else
            {
                if(str != "")
                {
                    stk.push(str);
                    str = "";
                }
            }
        }
        str = "";
        while(!stk.empty())
        {
            str += stk.top();
            str.push_back(' ');
            stk.pop();
        }
        str.pop_back();
        return str;
    }
};
