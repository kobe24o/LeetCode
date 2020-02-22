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
    int lastRemaining(int n, int m) {
        vector<int> num(n);
        int i;
        for(i = 0; i < n; i++)
            num[i] = i;
        i = 0;
        while(num.size() != 1)
        {
            i = (i+m-1)%num.size();
            num.erase(num.begin()+i);
            i--;
        }
        return num[0];
    }
};
int main()
{
    Solution s;
    vector<vector<int>> v = {{1,2,3},{4,5,6},{7,8,9}};
    s.lastRemaining(5,3);

}