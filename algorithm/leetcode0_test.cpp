/**
 * @description: 调试使用
 * @author: michael ming
 * @date: 2019/11/24 22:55
 * @modified by: 
 */
#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> c;
bool cmp(char& a, char& b)
{
    for(int j = 0; j < 26; j++)
    {
        if(c[a-'A'][j] == c[b-'A'][j])
            continue;
        return c[a-'A'][j] > c[b-'A'][j];
    }
    return a < b;
}
class Solution {
public:
    string rankTeams(vector<string>& votes) {
        int i, j;
        vector<int> t(26,0);
        for(i = 0; i < 26; ++i)
            c.push_back(t);
        for(i = 0; i < votes.size(); i++)
        {
            for(j = 0; j < votes[i].size(); j++)
                c[votes[i][j]-'A'][j]++;
        }
        sort(votes[0].begin(), votes[0].end(), cmp);
        cout <<  votes[0];
        return votes[0];
    }
};

int main()
{
     Solution s;
     vector<string> nums = {"BCA","CAB","CBA","ABC","ACB","BAC"};
     s.rankTeams(nums);
     return 0;
}