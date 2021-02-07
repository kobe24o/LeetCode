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
    string largestMerge(string word1, string word2) {
        int n1 = word1.size(), n2 = word2.size(), i = 0, j = 0;
        string ans;
        ans.reserve(n1+n2);
        while(i < n1 || j < n2)
        {
            if(i < n1 && j < n2 && word1[i] > word2[j])
                ans.push_back(word1[i++]);
            else if(i < n1 && j < n2 && word1[i] < word2[j])
                ans.push_back(word2[j++]);
            else if(i < n1 && j < n2 && word1[i] == word2[j])
            {
                int k1 = i, k2 = j;
                while(k1 < n1 && k2 < n2 && word1[k1] == word2[k2])
                {
                    k1++, k2++;
                }
                if((k1 < n1 && k2 < n2 && word1[k1] > word2[k2]) || (k2==n2 && k1<n1 && word1[k1] > word1[i])
                   || (k1==n1 && k2<n2 && word2[k2] < word1[i]) || (k1==n1 && k2==n2))
                {
                    for( ; i < k1; ++i)
                        ans.push_back(word1[i]);
                    if(k1 != n1)
                        ans.push_back(word1[i++]);
                }
                else if((k1 < n1 && k2 < n2 && word2[k2] > word1[k1]) || (k1==n1 && k2<n2 && word2[k2] > word1[i])
                        || (k2==n2 && k1<n1 && word1[k1] < word1[i]))
                {
                    for( ; j < k2; ++j)
                        ans.push_back(word2[j]);
                    if(k2 != n2)
                        ans.push_back(word2[j++]);
                }
                else
                {
                    for( ; i < k1; ++i)
                        ans.push_back(word1[i]);
                }
            }
            else if(i < n1 && j == n2)
                ans.push_back(word1[i++]);
            else
                ans.push_back(word2[j++]);
            // cout << i << " " << j << endl;
        }
        return ans;
    }
};


int main()
{

    Solution s;
    vector<vector<int>> g = {{1,2,4},{3,4,3},{2,3,10}};
    vector<int> a = {-3,-5,-3,-2,-6,3,10,-10,-8,-3,0,10,3,-5,8,7,-9,-9,5,-8};
    string str = "A man, a plan, a canal: Panama";
    string s1 = "guguuuuuuuuuuuuuuguguuuuguug",
           s2=     "gguggggggguuggguugggggg";
    cout << s.largestMerge(s1,s2) << endl;

//    cout << bool(true^false) << endl;
    return 0;
}