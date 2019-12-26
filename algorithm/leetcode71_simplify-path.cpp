#include <stack>
#include<string>
using namespace std;
class Solution {
public:
    string simplifyPath(string path) {
        stack<string> stk;
        string file;
        for(int i = 0; i < path.size(); ++i)
        {
            if(path[i] == '/')
            {
                if(file == "..")
                    if(!stk.empty())
                        stk.pop();
                else if(file != "")
                    stk.push(file);
                file = "";
            }
            else
            {
                file += path[i];
                if(i == path.size()-1)
                {
                    if(file == ".." && !stk.empty())
                        stk.pop();
                    else if(file != "")
                        stk.push(file);
                }
            }
        }
        stack<string> temp;
        while(!stk.empty())
        {
            temp.push(stk.top());
            stk.pop();
        }
        string ans;
        while(!temp.empty())
        {
            ans += '/'+temp.top();
            temp.pop();
        }
        if(ans == "")
            return "/";
        return ans;
    }
};

int main()
{
    Solution s;
    s.simplifyPath("/.../");
}