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
public:
    /**
     * @param version1: the first given number
     * @param version2: the second given number
     * @return: the result of comparing
     */
    int compareVersion(string &version1, string &version2) {
        // Write your code here
        int m = version1.size(), n = version2.size();
        int i = 0, j = 0;
        while(i < m && j < n) {
            int v1 = 0, v2 = 0;
            while(i < m && version1[i] != '.')
            {
                v1 = v1*10+version1[i++]-'0';
            }
            i++;
            while(j < m && version2[j] != '.')
            {
                v2 = v2*10+version2[j++]-'0';
            }
            j++;
            if(v1 < v2)
                return -1;
            else if(v1 > v2)
                return 1;
        }
        if(i < m) return 1;
        else if(j < n) return -1;
        return 0;
    }
};


int main()
{

    Solution s;
    vector<vector<int>> g = {{},{6},{5},{6},{3,6},{},{},{}};
    vector<int> a = {-1,-1,1,0,0,1,0,-1}, b = {15,15,15,15,15}, c={1,2,8,10,4};
    string str = "cdbcbbaaabab";
    string s1 = "01", s2 = "1";
    cout << s.compareVersion(s1,s2) << endl;


    return 0;
}