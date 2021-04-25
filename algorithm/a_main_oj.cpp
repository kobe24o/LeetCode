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
    int longestBeautifulSubstring(string word) {
        int n = word.size(), maxlen = 0;
        int i = 0, j = 0;
        while(j < n)
        {
            char c = char('a'-1);
            i = j;
            while(j < n && (word[j] == c || word[j] == c+1))
            {
                c = word[j];
                j++;
            }
            if(i == j)
                j++;//没有字符被遍历
            else if(word[j-1] == 'u')
                maxlen = max(maxlen, j-i);
        }
        return maxlen;
    }
};

int main()
{

    Solution s;
    vector<vector<int>> g = {{35,36},{11,7},{15,47},{34,2},{47,19},{16,14},{19,8},{7,34},{38,15},{16,18},{27,22},{7,15},{43,2},{10,5},{5,4},{3,11}};
    vector<int> c = {3,2,4}, d = {6,5};
    string str = "9";
    string s1 = "aeiaaioaaaaeiiiiouuuooaauuaeiu",
           s2=     "gguggggggguuggguugggggg";
    cout << s.longestBeautifulSubstring(s1) << endl;
    return 0;
}