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

void calNexts(char *b, int m, vector<int>& next)
{
    next[0] = -1;
    int j = 0, k = -1;
    while(j < m)
    {
        if(k == -1 || b[j] == b[k])
        {
            j++;k++;
            next[j] = k;
        }
        else
            k = next[k];
    }
    //    for(j = 0; j < m; ++j)//调试代码
    //        cout << "next[" << j << "] " << next[j] << endl;
}
int str_kmp(char *a, int n, char *b, int m)
{
    vector<int> next(m);
    calNexts(b, m, next);
    int i = 0, j = 0;
    while(i < n && j < m)
    {
        if(j == -1 || a[i] == b[j])
        {
            i++;j++;
        }
        else
        {
            j = next[j];
        }
    }
    if(j == m)
    {
        return i-j;
    }
    return -1;
}

int main()
{

//    Solution s;
    vector<vector<int>> g = {{35,36},{11,7},{15,47},{34,2},{47,19},{16,14},{19,8},{7,34},{38,15},{16,18},{27,22},{7,15},{43,2},{10,5},{5,4},{3,11}};
    vector<int> c = {1,2,3, 3}, d = {6,5};
    string str = "9";
    string s1 = "guguuuuuuuuuuuuuuguguuuuguug",
           s2=     "gguggggggguuggguugggggg";
//    cout << s.getXORSum(a,b) << endl;

    string a = "hello", b = "ll";
    int p = str_kmp(&a[0],a.size(),&b[0],b.size());
    cout << a << " find " << b << " at ： " << p << endl;
    return 0;
}