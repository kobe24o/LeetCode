class Solution {
public:
    int minInsertions(string s) {
        int sum = 0;
        stack<char> stk;
        int n = s.size();
        for(int i = 0; i < n; ++i)
        {
            if(s[i] == '(')
                stk.push('(');
            else if(s[i] == ')')
            {
                if(i+1 < n && s[i+1] == ')')
                {
                    if(!stk.empty())
                        stk.pop();// ())消除
                    else
                        sum++;//补一个左括号
                    i++;//后面的 ) 已经处理了
                }
                else//后面没有 ）
                {
                    if(!stk.empty())
                    {   //有左括号
                        stk.pop();
                        sum++;// 补一个右括号
                    }
                    else//没有左括号
                        sum += 2;//补一个左，一个右括号
                }
            }
        }
        while(!stk.empty())
        {
            stk.pop();
            sum += 2;
        }
        return sum;
    }
};

class Solution {
public:
    int minInsertions(string s) {
        //先预处理，把 （ 变成 （（
        string ans;
        int l = 0, r = 0, sum = 0;
        for(int i = 0; i < s.size(); ++i)
        {
            if(i+1 < s.size() && s[i]==')' && s[i+1] == ')')
            {
                ans += ")";//连续的两个变成1个 ）
                i++;
                continue;
            }
            if(s[i] == ')')
                sum++;
            ans += s[i];
        }
        for(int i = 0; i < ans.size(); ++i)
        {
            if(ans[i] == '(') 
                l++;
            else
            {
                if(l>0) //右括号可以与之匹配
                    l--;
                else //右括号没有相应的左括号匹配
                    r++;
            }   
        }
        return 2*l+r+sum;
    }
};