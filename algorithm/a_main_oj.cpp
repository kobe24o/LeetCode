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

struct cmp{
    bool operator()(char a, char b) const
    {
        return a > b;
    }
};
class Solution {
public:
    int stoneGameVI(vector<int>& aliceValues, vector<int>& bobValues) {
        int n = aliceValues.size();
        vector<pair<int, int>> diff(n);
        for(int i = 0; i < n; i++)
        {
            diff[i].first = aliceValues[i]-bobValues[i];
            diff[i].second = i;
        }
        sort(diff.begin(), diff.end());
        int a = 0, b = 0, i = 0, j = n-1;
        bool alice = true;
        while(i <= j)
        {
            if(alice)
            {
                a += aliceValues[diff[j].second];
                j--;
                alice = false;
            }
            else
            {
                b += bobValues[diff[i].second];
                i++;
                alice = true;
            }
        }
        if(a > b) return 1;
        else if(a < b) return -1;
        return 0;
    }
};
int main()
{

    Solution s;
    vector<int> a = {1,2}, b = {3, 1};
    string s1 = "D450";
    cout << s.stoneGameVI(a, b) << endl;
    return 0;
}