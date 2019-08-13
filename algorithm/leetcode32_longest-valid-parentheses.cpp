/**
 * @description: 
 * @author: michael ming
 * @date: 2019/8/12 23:34
 * @modified by: 
 */
#include <string>
#include <stack>
#include <iostream>

using namespace std;
class Solution
{
public:
    int longestValidParentheses(string s)
    {
        int count = 0, maxlen = 0;
        stack<int> stk;
        stk.push(-1);
        for(int i = 0; i < s.size(); ++i)
        {
            if(s[i] == '(')
            {
                stk.push(i);
            }
            else    // s[i] == ')'
            {
                stk.pop();
                if(!stk.empty())
                {
                    count = i-stk.top();
                    if(count > maxlen)
                        maxlen = count;
                }
                else
                    stk.push(i);
            }
        }
        return maxlen;
    }
};
int main()
{
    Solution slo;
    string str = "())(())";
    cout << slo.longestValidParentheses(str);
    return 0;
}