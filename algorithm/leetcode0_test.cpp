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
struct cmp
{
    bool operator()(const pair<int,int>& a, const pair<int,int>& b)const
    {
        return a.second-a.first < b.second-b.first;
    }
};
class Solution {
public:
    int maxSideLength(vector<vector<int>>& mat, int threshold) {
        int m = mat.size(), n = mat[0].size(), i, j, maxlen = 0, len = 0;
        vector<vector<int>> sum(m,vector<int>(n,0));
        for(j = 0; j < n; ++j)
            sum[0][j] = j > 0 ? sum[0][j-1] : 0 + mat[0][j];
        for(i = 1; i < m; ++i)
            sum[i][0] = sum[i-1][0] + mat[i][0];
        for(i = 1; i < m; ++i)
            for(j = 1; j < n; ++j)
                sum[i][j] = sum[i-1][j] + sum[i][j-1] - sum[i-1][j-1]+mat[i][j];
        int ni, nj, sumofarea;
        for(i = 0; i < m; ++i)
            for(j = 0; j < n; ++j)
                for(len = 1; len <= min(m,n); ++len)
                {
                    ni = i+len-1;
                    nj = j+len-1;
                    if(ni < m && nj < n)
                    {
                        sumofarea = sum[ni][nj]-(i>0?sum[i-1][nj]:0)-(j>0?sum[ni][j-1]:0)
                                    +(i>0&&j>0 ? sum[i-1][j-1] : 0);
                        if(sumofarea <= threshold)
                        {
                            cout << ni << nj << i << j << endl;
                            maxlen = max(maxlen, len);
                            if(maxlen == min(m,n))
                                return maxlen;
                        }
                    }
                    else
                        break;
                }
        return maxlen;
    }
};
void printv(vector<int>& v)
{
    for(auto& vi : v)
        cout << vi << " ";
    cout << endl;
}
int main() {
    vector<vector<int>> v6 ={{2,2,2,2,2},{2,2,2,2,2},{2,2,2,2,2},{2,2,2,2,2},{2,2,2,2,2}};
    vector<vector<int>> v5 ={{0,4},{4,0},{1,3},{3,0}};
    vector<int> v1 = {197,130,1};
    vector<int> v2 = {5,4,0,3,1,6,2};
    vector<int> v3 = {332484035, 524908576, 855865114, 632922376, 222257295, 690155293, 112677673, 679580077, 337406589, 290818316, 877337160, 901728858, 679284947, 688210097, 692137887, 718203285, 629455728, 941802184};
    vector<int> v4 = {};
    string str = "eceeeefasdghjklqwertyuio";
    vector<vector<string>> st  = {{"A","B"},{"C"},{"B","C"},{"D"}};

    vector<string> st1 = {"havana"};
    Solution s;
    s.maxSideLength(v6,1);
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