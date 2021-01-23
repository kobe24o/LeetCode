#include <bits/stdc++.h>

using namespace std;
void print2Dvector(vector<vector<int>>& a)
{
    int m = a.size(), n = a[0].size();
    for(int i = 0; i < m; ++i)
    {
        for(int j = 0; j < n; ++j)
            cout << a[i][j] << " ";
        cout << endl;
    }
}

class Solution {
    unordered_map<string,unordered_map<string,bool>> m;
public:
    bool isScramble(string s1, string s2) {
        if(m.count(s1) && m[s1].count(s2))
            return m[s1][s2];
        if(s1 == s2) return true;
        for(int len = 0; len <= s1.size(); ++len)
        {
            string s1a = s1.substr(0,len), s1b = s1.substr(len);
            string s2a = s2.substr(0,len), s2b = s2.substr(len);
            string s2a_ = s2.substr(0,s2.size()-len), s2b_ = s2.substr(s2.size()-len);
            if(isScramble(s1a, s2a) && isScramble(s1b, s2b))
                return m[s1][s2] = true;
            if(isScramble(s1a, s2b_) && isScramble(s1b, s2a_))
                return m[s1][s2] = true;
        }
        return m[s1][s2] = false;
    }
};


int main()
{

    Solution s;
    vector<vector<int>> g = {{},{6},{5},{6},{3,6},{},{},{}};
    vector<int> a = {-1,-1,1,0,0,1,0,-1}, b = {15,15,15,15,15}, c={1,2,8,10,4};
    string str = "cdbcbbaaabab";
    string s1 = "rgeat", s2 = "great";
    cout << s.isScramble(s1,s2) << endl;


    return 0;
}