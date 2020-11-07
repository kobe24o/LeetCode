#include <bits/stdc++.h>

using namespace std;


struct cmp{
    bool operator()(char a, char b) const
    {
        return a > b;
    }
};
#include<vector>
#include<math.h>
#include<string.h>
#include<iostream>
using namespace std;

class Solution {
public:
    int expressiveWords(string S, vector<string>& words) {
        if(S == "") return 0;
        int ans = 0, num = 0;
        vector<char> S_char;
        vector<int> count;
        char prev = S[0];
        for(int i = 0; i < S.size(); i++)
        {
            if(S[i] != prev)
            {
                S_char.push_back(prev);
                count.push_back(num);
                num = 1;
                prev = S[i];
            }
            else
            {
                num++;
            }
        }
        S_char.push_back(prev);
        count.push_back(num);
        for(auto& w : words)
        {
            if(w == "")
                continue;
            bool flag = true;
            int i = 0;
            num = 0;
            prev = w[0];
            for(int j = 0; j < w.size(); j++)
            {
                if(w[j] != prev)
                {
                    if(i == S_char.size() || prev != S_char[i]
                       || (count[i] != num && count[i]-num < 2))
                    {
                        flag = false;
                        break;
                    }
                    i++;
                    num = 1;
                    prev = w[j];
                }
                else
                {
                    num++;
                }
            }
            if(i == S_char.size() || prev != S_char[i]
               || (count[i] != num && count[i]-num < 2))
                flag = false;
            if(flag && i == S_char.size()-1)
                ans++;
        }
        return ans;
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
    vector<string> w = {"dinnssoo","ddinso","ddiinnso","ddiinnssoo","ddiinso","dinsoo","ddiinsso","dinssoo","dinso"};
    cout << s.expressiveWords("dddiiiinnssssssoooo", w) << endl;
    return 0;
}