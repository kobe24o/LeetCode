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
    int minOperations(vector<int>& nums1, vector<int>& nums2) {
        int len1 = nums1.size(), len2 = nums2.size();
        if(len1 > 6*len2 || len2 > 6*len1) return -1;
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        int s1 = accumulate(nums1.begin(), nums1.end(),0);
        int s2 = accumulate(nums2.begin(), nums2.end(),0);
        if(s1 > s2)
        {
            swap(nums1, nums2);
            swap(s1, s2);
            swap(len1, len2);
        }
        // 令 s1 <= s2
        int ans = 0, i = 0, j = len2-1;
        int delta1, delta2;
        while(s1 != s2 && (i < len1 || j >= 0))
        {
            delta1 = i < len1 ? 6-nums1[i] : 0;
            delta2 = j >= 0 ? nums2[j]-1 : 0;
            if(s2-s1 > 5)
            {
                if(delta1 >= delta2)
                {
                    s1 += delta1;
                    i++;
                }
                else
                {
                    s2 -= delta2;
                    j--;
                }
                ans++;
            }
            else if(s2-s1 <= 5)
            {
                if(delta1 >= s2-s1 || delta2 >= s2-s1)
                    return ++ans;
                else
                {
                    s1 += delta1;
                    s2 -= delta2;
                    ans += 2;
                    i++,j--;
                }
            }
        }
        return ans;
    }
};


int main()
{

    Solution s;
    vector<vector<int>> g = {{1,2,4},{3,4,3},{2,3,10}};
    vector<int> a = {3,3,2,4,2,6,2}, b = {6,2,6,6,1,1,4,6,4,6,2,5,4,2,1};
    string str = "A man, a plan, a canal: Panama";
    string s1 = "guguuuuuuuuuuuuuuguguuuuguug",
           s2=     "gguggggggguuggguugggggg";
//    cout << s.largestMerge(s1,s2) << endl;
    vector<int> arr = {1,2,3,4,5,6};
    arr.reserve(4);
    for(auto a : arr)
        cout << a << endl;
    cout << s.minOperations(a,b) << endl;
    return 0;
}