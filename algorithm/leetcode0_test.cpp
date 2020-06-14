/**
 * @description: 调试使用
 * @author: michael ming
 * @date: 2019/11/24 22:55
 * @modified by: 
 */
#include <bits/stdc++.h>
struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(NULL) {}
};
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
using namespace std;
class dsu
{
public:
    vector<int> f;

    dsu(int n)
    {
        f.resize(n+1);
        for(int i = 0; i < n+1; ++i)
            f[i] = i;
    }
    void merge(int a, int b)
    {
        f[a] = b;
    }
    int find(int a)
    {
        int origin = a;
        while(a != f[a])
            a = f[a];
        return f[origin] = a;
    }
};
class trie
{
public:
    trie* next[26] = {NULL};
    bool isend =  false;
    int count = 0;
    void insert(string& s)
    {
        trie* cur = this;
        for(int i = 0; i < s.size(); i++)
        {
            if(cur->next[s[i]-'a'] == NULL)
                cur->next[s[i]-'a'] = new trie();
            cur = cur->next[s[i]-'a'];
        }
        cur->count++;
        cur->isend = true;
    }
};
class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int i=0, j=0, n = arr.size(), sum = 0;
        vector<pair<int,int>> v;
        for(j = 0; j < n; )
        {

            if(sum > target)
            {
                sum -= arr[i++];
                if(sum==target)
                    v.push_back({i,j-1});
            }
            else
            {

                if(sum==target)
                    v.push_back({i,j-1});
                sum += arr[j];
                j++;
            }
        }
        while(i < n)
        {
            if(sum==target)
                v.push_back({i,j-1});
            sum -= arr[i++];
        }
        sort(v.begin(),v.end(),[&](pair<int,int> a, pair<int,int> b){
            if ((a.second-a.first) == (b.second-b.first))
                return a.first < b.first;
            return (a.second-a.first) < (b.second-b.first);
        });
        int minlen = INT_MAX;
        for(i = 0; i < v.size(); ++i)
        {
            for(j = 0; j < v.size(); ++j)
            {
                if(i==j)
                    continue;
                if(v[i].second < v[j].first || v[i].first > v[j].second)
                {
                    minlen = min(minlen, v[i].second-v[i].first+v[j].second-v[j].first+2);
                    // break;
                }
            }
        }
        return minlen==INT_MAX? -1 : minlen;
    }
};
void printv(vector<int>& v)
{
    for(auto& vi : v)
        cout << vi << " ";
    cout << endl;
}
int main() {
//    vector<vector<int>> v6 = {{-13260,8589},{1350,8721},{-37222,-19547},{-54293,-29302},{-10489,-13241},{-19382,574},{5561,1033},{-22508,-13241},{-1542,20695},{9277,2820},{-32081,16145},{-50902,23701},{-8636,19504},{-17042,-28765},{-27132,-24156},{-48323,-4607},{30279,29922}};
    vector<vector<int>> v6 ={{0,1},{1,2},{2,3},{3,4}};
    vector<vector<int>> v5 ={{0,4},{4,0},{1,3},{3,0}};
    vector<int> v1 = {197,130,1};
    vector<int> v2 = {1,2,2,3,2,6,7,2,1,4,8};
    vector<int> v3 = {332484035, 524908576, 855865114, 632922376, 222257295, 690155293, 112677673, 679580077, 337406589, 290818316, 877337160, 901728858, 679284947, 688210097, 692137887, 718203285, 629455728, 941802184};
    vector<int> v4 = {};
    string str = "eceeeefasdghjklqwertyuio";
    vector<vector<string>> st  = {{"A","B"},{"C"},{"B","C"},{"D"}};

    vector<string> st1 = {"havana"};
    Solution s;
    s.minSumOfLengths(v2,5);
    printv(v4);

    string s1 = "1";
    cout << s1[1] << "s[1]" << endl;
    TreeNode *t1 = new TreeNode(0);
    TreeNode *t2 = new TreeNode(1);
    TreeNode *t3 = new TreeNode(2);
    TreeNode *t4 = new TreeNode(3);
    TreeNode *t5 = new TreeNode(4);
    t1->left = t2;
    t1->right = t3;
    t2->left = t4;
    t2->right = t5;


    ListNode *h1 = new ListNode(3);
    ListNode *h2 = new ListNode(5);
    ListNode *h3 = new ListNode(8);
    ListNode *h4 = new ListNode(5);
    ListNode *h5 = new ListNode(10);
    ListNode *h6 = new ListNode(2);
    ListNode *h7 = new ListNode(1);
    h1->next = h2;
    h2->next = h3;
    h3->next = h4;
    h4->next = h5;
    h5->next = h6;
    h6->next = h7;
    vector<int> a = {1,2,3};
    cout << a.size() << endl;
    a.resize(a.size()+5);
    cout << a.size() << endl;
    for(int i = 0; i < 8; ++i)
        cout << a[i] << endl;
    return 0;
}