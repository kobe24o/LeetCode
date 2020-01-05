/**
 * @description: 调试使用
 * @author: michael ming
 * @date: 2019/11/24 22:55
 * @modified by: 
 */
#include <bits/stdc++.h>
using namespace std;
int main()
{
    vector<int> v = {1,1,2,3,3,4,5,5,6,1};
    v.erase(unique(v.begin(), v.end()),v.end());
    cout << "";
}
