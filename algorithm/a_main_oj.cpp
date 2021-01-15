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
    int kind;
    unordered_set<int> s;
    string ans;
    vector<int> unit = {0, 1, 10, 100, 1000};
public:
    string crackSafe(int n, int k) {
        kind = pow(k, n);
        string temp;
        dfs(temp, 0, n, k);
        return ans;
    }
    void dfs(string& temp,  int num, int n, int k)
    {
        if(s.size() == kind)
        {
            if(ans == "" || temp.size() < ans.size())
                ans = temp;
            return;
        }
        int newnum;
        for(int i = 0; i < k; i++)
        {
            if(temp.size() < n)
            {
                temp += char('0'+i);
                newnum = num*10 + i;
                if(temp.size() == n)
                    s.insert(newnum);
                dfs(temp, newnum, n, k);
                if(temp.size() == n)
                    s.erase(newnum);
            }
            else
            {
                newnum = num - unit[n]*(temp[temp.size()-n]-'0');
                temp += char('0'+i);
                newnum = newnum*10 + i;
                if(!s.count(newnum))
                {
                    s.insert(newnum);
                    dfs(temp, newnum, n, k);
                    s.erase(newnum);
                }
            }
            temp.pop_back();
        }
    }
};


int main()
{

    Solution s;
    vector<vector<int>> g = {{},{6},{5},{6},{3,6},{},{},{}};
    vector<int> a = {-1,-1,1,0,0,1,0,-1}, b = {15,15,15,15,15}, c={1,2,8,10,4};
    string str = "cdbcbbaaabab";
    cout << s.crackSafe(3,5) << endl;


    return 0;
}