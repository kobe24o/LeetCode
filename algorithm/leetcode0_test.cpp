/**
 * @description: 调试使用
 * @author: michael ming
 * @date: 2019/11/24 22:55
 * @modified by: 
 */
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        sort(folder.begin(), folder.end());
        int i;
        vector<string> ans(1,folder[0]);
        bool issub = false;
        string str = folder[0]+"/";
        for(i = 1; i < folder.size(); ++i)
        {
            while((i < folder.size()) && (folder[i].find(str) != folder[i].npos))
                i++;
            if(i < folder.size())
            {
                ans.push_back(folder[i]);
                str = ans.back()+"/";
            }

        }
        return ans;
    }
};
int main()
{
    Solution s;
    vector<string> v{"/a","/a/b","/c/d","/c/d/e","/c/f"};
    s.removeSubfolders(v);
}