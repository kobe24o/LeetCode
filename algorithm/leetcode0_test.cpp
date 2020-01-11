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
    int distinctEchoSubstrings(string text) {
        int i, len, n = text.size(), count = 0;
        string s, doubS;
        for(len = 1; len <= n/2+1; len++)
        {
            for(i = 0; i <= n-len; ++i)
            {
                s = text.substr(i, len);
                doubS = s+s;
                if(text.find(doubS) != text.npos)
                    count++;
            }
        }
        return count;
    }
};
int main()
{
    Solution s;
    s.distinctEchoSubstrings("abcabcabc");
}