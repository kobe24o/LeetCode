#include <bits/stdc++.h>

using namespace std;


struct cmp{
    bool operator()(char a, char b) const
    {
        return a > b;
    }
};
class Solution {
public:
    /**
     * @param s: a String
     * @return: if valid return "YES" else return "NO"
     */
    string isValid(string &s) {
        // write your code here
        unordered_map<char, int> m;
        for(char c : s)
            m[c]++;
        map<int, int> count;
        for(auto &mi : m)
            count[mi.second]++;
        if(count.size() > 2)
            return "NO";
        if(count.size() == 1)
            return "YES";
        int diff = 0;
        int a = count.begin()->first, b = count.rbegin()->first;
        int n2 = count.rbegin()->second;
        if(b-a==1 && n2 == 1)
            return "YES";
        return "NO";
    }
};
int main()
{
    // int N, V, vi, si;
    // while(cin >> V >> N)
    // {
    //     int maxprice = 0;
    //     vector<int> dp(V+1, -1);
    //     dp[0] = 0;// dp[v] 表示体积为 v 时装的最大价值
    //     for(int i = 0; i < N; ++i)
    //     {
    //         cin >> si >> vi;
    //         vector<int> temp(V+1, -1);
    //         for(int j = 0; j <= V; ++j)
    //         {
    //             if(dp[j] == -1)//状态不存在
    //                 continue;
    //             for(int s = 0; s <= si; ++s)
    //             {   //当前的物品可以拿 s 次
    //                 if(j+s*vi > V)//体积超了，不行
    //                     break;
    //                 temp[j+s*vi] = max(temp[j+s*vi], dp[j]+s*vi);
    //                 maxprice = max(maxprice, temp[j+s*vi]);
    //             }
    //         }
    //         swap(dp, temp);
    //     }
    //     cout << maxprice << endl;
    // }
    Solution s;
    vector<int> a = {1,3,4,1,5};
    string s1 = "aabbcd";
    cout << s.isValid(s1) << endl;
    return 0;
}