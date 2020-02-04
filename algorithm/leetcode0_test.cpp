/**
 * @description: 调试使用
 * @author: michael ming
 * @date: 2019/11/24 22:55
 * @modified by: 
 */
#include <bits/stdc++.h>
using namespace std;

#include<set>
#include<vector>
#include<iostream>
using namespace std;
int main()
{
    int N, n, i=0, ans;
    cin >> N;
    n = N;
    vector<int> arr(N);
    while(n--)
        cin >> arr[i++];
    set<int> s;
    for(i = 0; i < N; ++i)
        s.insert(arr[i]);
    i = 0;
    for(auto& it : s)
    {
        i++;
        ans = it;
        if(i == 3)
            break;
    }
    cout << ans;
    return ans;
}