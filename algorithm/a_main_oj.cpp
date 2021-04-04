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
    int countNicePairs(vector<int>& nums) {
        long long n = nums.size(), n1 = 0;
        map<vector<int>, long long> m;//编码，个数
        for(int i = 0; i < n; i++) {
            if(ispal(nums[i]))
                n1++;
            else
            {
                int n = nums[i];
                vector<int> bit, key;
                while(n)
                {
                    bit.push_back(n%10);
                    n /= 10;
                }
                for(int i = 1; i < bit.size(); i++)
                {
                    key.push_back(bit[i]-bit[i-1]);
                }
                m[key]++;
            }
        }
        long long ans = n1*(n1-1)/2, mod = 1e9+7;
        for(auto it = m.begin(); it != m.end(); ++it)
        {
            ans = (ans + it->second * (it->second-1)/2)%mod;
        }
        return ans;
    }
    bool ispal(int x)
    {
        string sx = to_string(x);
        string y = sx;
        reverse(y.begin(), y.end());
        return y==sx;
    }
};


int main()
{

    Solution s;
    vector<vector<int>> g = {{1,2,4},{3,4,3},{2,3,10}};
    vector<int> a = {352171103,442454244,42644624,152727101,413370302,293999243}, b = {6,2,6,6,1,1,4,6,4,6,2,5,4,2,1};
    string str = "9";
    string s1 = "guguuuuuuuuuuuuuuguguuuuguug",
           s2=     "gguggggggguuggguugggggg";
//    cout << s.largestMerge(s1,s2) << endl;
    vector<int> arr = {1,2,3,4,5,6};
    arr.reserve(4);
    for(auto a : arr)
        cout << a << endl;
    cout << s.countNicePairs(a) << endl;
    for(int i = 0; i < a.size(); ++i)
    {
        for(int j = i+1; j < a.size(); ++j)
        {
            string x = to_string(a[i]);
            string y = to_string(a[j]);
            reverse(x.begin(), x.end());
            reverse(y.begin(), y.end());
            int X = stoi(x), Y = stoi(y);
            if(a[i]+Y == X+a[j])
                cout << a[i] << " " << a[j] << endl;
        }
    }
    return 0;
}