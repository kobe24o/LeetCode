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
            if(path[i] == '/' || i == path.size()-1)
            {
                if(file != "")
                    stk.push(file);
                file = "";
            }
            else if(path[i] == '.')
            {
                if(i+1 < path.size() && path[i+1] == '.' && (i+2 == path.size() || path[i+2] == '/'))
                {
                    if(!stk.empty())
                        stk.pop();
                    i++;
                }
                else if(i+1 < path.size() && path[i+1] == '.' && i+2 < path.size() && path[i+2] != '/')
                {
                    file = ".."+path[i+2];
                    i += 2;
                }
            }
            else
            {
                file += path[i];
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
    s.simplifyPath("/..hidden");
}