#include <stack>
#include<string>
using namespace std;
class Solution {
public:
    string simplifyPath(string path) {
        stack<string> stk;
        string file;
        path += '/';
        for(int i = 0; i < path.size(); ++i)
        {
            if(path[i] == '/')
            {
                if(file == "..")
                {
                    if(!stk.empty())
                        stk.pop();
                }
                else if(file != "" && file != ".")
                    stk.push(file);
                file = "";
            }
            else// ！= '/'
            {
                file += path[i];
            }
        }

        string ans;
        while(!stk.empty())
        {
            ans = '/'+stk.top()+ans;
            stk.pop();
        }
        if(ans == "")
            return "/";
        return ans;
    }
};

int main()
{
    Solution s;
    s.simplifyPath("/a//b////c/d//././/..");
}