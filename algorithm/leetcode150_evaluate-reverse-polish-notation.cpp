/**
 * @description: 
 * @author: michael ming
 * @date: 2019/8/13 23:29
 * @modified by: 
 */
#include <string>
#include <vector>
#include <stack>

using namespace std;
class Solution
{
public:
    int evalRPN(vector<string>& tokens)
    {
        stack<int> intStk;
        int a, b;
        for(int i = 0; i < tokens.size(); ++i)
        {
            if(tokens[i] != "+" && tokens[i] != "-" &&
               tokens[i] != "*" && tokens[i] != "/")
                intStk.push(atoi(&tokens[i][0]));
            else
            {
                a = intStk.top();
                intStk.pop();
                b = intStk.top();
                intStk.pop();
                if(tokens[i] == "+")
                    intStk.push(b + a);
                else if(tokens[i] == "-")
                    intStk.push(b - a);
                else if(tokens[i] == "*")
                    intStk.push(b * a);
                else
                    intStk.push(b / a);
            }
        }
        return intStk.top();
    }
};