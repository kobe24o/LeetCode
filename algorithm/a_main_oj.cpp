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
    int numDifferentIntegers(string word) {
        word.push_back('a');
        unordered_set<int> s;
        int num = -1;
        char prev = '*';
        for(auto c : word) {
            if(isalpha(c))
            {
                if(num != -1)
                {
                    s.insert(num);
                    num = -1;
                }
            }
            else//数字
            {
                if(isalpha(prev))
                    num = 0;
                num = num*10+c-'0';
            }
            prev = c;
        }
        return s.size();
    }
};


int main()
{

    Solution s;
    vector<vector<int>> g = {{1,2,4},{3,4,3},{2,3,10}};
    vector<int> a = {3,3,2,4,2,6,2}, b = {6,2,6,6,1,1,4,6,4,6,2,5,4,2,1};
    string str = "9";
    string s1 = "guguuuuuuuuuuuuuuguguuuuguug",
           s2=     "gguggggggguuggguugggggg";
//    cout << s.largestMerge(s1,s2) << endl;
    vector<int> arr = {1,2,3,4,5,6};
    arr.reserve(4);
    for(auto a : arr)
        cout << a << endl;
    cout << s.numDifferentIntegers(str) << endl;
    return 0;
}