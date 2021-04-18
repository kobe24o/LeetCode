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
    int getXORSum(vector<int>& arr1, vector<int>& arr2) {
        int n1 = arr1.size(), n2 = arr2.size();
        int ans = 0;
        for(int i = 0; i < n1; i++) {
            for(int j = 0; j < n2; j++) {
                ans ^= arr1[i]&arr2[j];
            }
        }
        return ans;
    }
};


int main()
{

    Solution s;
    vector<vector<int>> g = {{35,36},{11,7},{15,47},{34,2},{47,19},{16,14},{19,8},{7,34},{38,15},{16,18},{27,22},{7,15},{43,2},{10,5},{5,4},{3,11}};
    vector<int> a = {1,2,3, 3}, b = {6,5};
    string str = "9";
    string s1 = "guguuuuuuuuuuuuuuguguuuuguug",
           s2=     "gguggggggguuggguugggggg";
    cout << s.getXORSum(a,b) << endl;
    return 0;
}