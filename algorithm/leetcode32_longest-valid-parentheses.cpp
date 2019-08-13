/**
 * @description: 
 * @author: michael ming
 * @date: 2019/8/12 23:34
 * @modified by: 
 */
#include <string>
#include <stack>
#include <iostream>
#include <memory.h>

using namespace std;
class Solution
{
public:
//    int longestValidParentheses(string s)
//    {
//        int count = 0, maxlen = 0;
//        stack<int> stk;
//        stk.push(-1);
//        for(int i = 0; i < s.size(); ++i)
//        {
//            if(s[i] == '(')
//            {
//                stk.push(i);
//            }
//            else    // s[i] == ')'
//            {
//                stk.pop();
//                if(!stk.empty())
//                {
//                    count = i-stk.top();
//                    if(count > maxlen)
//                        maxlen = count;
//                }
//                else
//                    stk.push(i);
//            }
//        }
//        return maxlen;
//    }
    int longestValidParentheses(string s)// DP解法
    {
        if(s.size() <= 1)
            return 0;
        int dp[s.size()];
        int maxlen = 0, k, i;
        memset(dp,0,s.size()*sizeof(int));
        for(i = 1; i < s.size(); ++i)
        {
            if(s[i] == ')')
            {
                if(s[i-1] == '(')
                {
                    if(i >= 2)
                        dp[i] = dp[i-2] + 2;
                    else
                        dp[i] = 2;
                }
                else// s[i-1] = ')'
                {
                    k = i-1-dp[i-1];
                    if(k >= 0 && s[k] == '(')
                    {
                        if(k >= 1)
                            dp[i] = dp[i-1] + dp[k-1] + 2;
                        else
                            dp[i] = dp[i-1] + 2;
                    }
                }
            }
        }
        for(i = 0; i < s.size(); ++i)
        {
            if(dp[i] > maxlen)
                maxlen = dp[i];
        }
        return maxlen;
    }
};
int main()
{
    Solution slo;
    string str = ")()())";
    cout << slo.longestValidParentheses(str);
    return 0;
}