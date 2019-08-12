/**
 * @description: 
 * @author: michael ming
 * @date: 2019/8/12 22:40
 * @modified by: 
 */
#include <string>
#include <stack>
using namespace std;
class Solution
{
public:
    bool isValid(string s)
    {
        stack<char> stk;
        for(int i = 0; i < s.size(); ++i)
        {
            if(s[i] == '(' || s[i] == '[' || s[i] == '{')
                stk.push(s[i]);
            else if(s[i] == ')' || s[i] == ']' || s[i] == '}')
            {
                if(!stk.empty() && ((stk.top() == '(' && s[i] == ')')||
                    (stk.top() == '[' && s[i] == ']')||
                    (stk.top() == '{' && s[i] == '}')))
                {
                    stk.pop();
                    continue;
                }
                else
                    return false;
            }
        }
        if(stk.empty())
            return true;
        else
            return false;
    }
};