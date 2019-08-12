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
        for(int i = 0; i < s.size(); ++i)
        {
            if(s[i] == '(')
            {
                stk.push(i);
            }
            else    // s[i] == ')'
            {
                if(!stk.empty())
                {
                    count = (i-stk.top()+1);
                    stk.pop();
                    if(count > maxlen)
                        maxlen = count;
                }
                else
                    count = 0;
            }
        }
        return maxlen;
    }
};
int main()
{
    Solution slo;
    string str = "()(())";
    cout << slo.longestValidParentheses(str);
    return 0;
}