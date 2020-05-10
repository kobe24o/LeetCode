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


struct cmp1
{
    bool operator()(const vector<int>& a, const vector<int>& b)const
    {
        if(a[0]==b[0])
        {
            if(a[1]==b[1])
                return a[2] < b[2];
            return a[1] < b[1];
        }
        return a[0] < b[0];
    }
};

class dsu
{
public:
    vector<int> f;
    dsu(int n)
    {
        f.resize(n);
        for(int i = 0; i < n; ++i)
            f[i] = i;
    }
    int find(int x)
    {
        if(x == f[x])
            return x;
        return f[x] = find(f[x]);
    }
    void merge(int x, int y)
    {
        int fx = find(x), fy = find(y);
        if(fx != fy)
            f[fx] = fy;
    }
};
class Solution {
public:
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        int n = s.size(), i, fatherid;
        dsu uni(n);
        for(i = 0; i < pairs.size(); ++i)
        {
            if(pairs[i][0] > pairs[i][1])
                swap(pairs[i][0],pairs[i][1]);
            uni.merge(pairs[i][0],pairs[i][1]);
        }
        unordered_map<int,set<char>> m;
        for(i = 0; i < n; ++i)
        {
            // fatherid = uni.f[i];//错误解
            uni.find(i);
        }
        for(i = 0; i < n; ++i)
        {
            // fatherid = uni.f[i];//错误解
            fatherid = uni.find(i);
            m[fatherid].insert(s[i]);
        }
        for(i = 0; i < n; ++i)
        {
            // fatherid = uni.f[i];
            fatherid = uni.find(i);
            s[i] = *m[fatherid].begin();
            m[fatherid].erase(m[fatherid].begin());
        }
        return s;
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
    vector<vector<int>> v6 ={{5,3},{3,0},{5,1},{1,1},{1,5},{3,0},{0,2}};
    vector<vector<int>> v5 ={{2,11,3},{15,10,7},{9,17,12},{8,1,14}};
    vector<int> v1 = {2,5,1,1,1,1};
    vector<int> v2 = {1,3,5};
    vector<int> v3 = {-1,0};
    vector<int> v4 = {2,7,9,4,4};
    string str = "eceeeefasdghjklqwertyuio";
    vector<vector<string>> st  = {{"David","3","Ceviche"},{"Corina","10","Beef Burrito"},{"David","3","Fried Chicken"},{"Carla","5","Water"},{"Carla","5","Ceviche"},{"Rous","3","Ceviche"}};
    vector<string> st1 = {};
    Solution s;
    s.smallestStringWithSwaps("pwqlmqm",v6);
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