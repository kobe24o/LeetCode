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
    void merge(int a, int b)
    {
        int fa = find(a);
        int fb = find(b);
        f[fa] = fb;
    }
    int find(int a)
    {
        int origin = a;
        while(a != f[a])
            a = f[a];
        return f[origin] = a;
    }
    int countUni(vector<vector<int>> &positions, int stop, vector<vector<int>> &grid, int n)
    {
        int count = 0, x, y, pos;
        for(int i = 0; i <= stop; ++i)
        {
            x = positions[i][0], y = positions[i][1];
            pos = x*n+y;
            if(pos == find(pos))
                count++;
        }
        return count;
    }
};

class Solution {
public:
    double getMinDistSum(vector<vector<int>>& positions) {
        int x0,y0, i, xi,yi, n = positions.size(), dis;
        set<int> d;
        for(x0 = 1; x0 <= 3; ++x0)
        {
            for(y0 = 1; y0 <= 3; ++y0)
            {
                dis = 0;
                for(i = 0; i < n; ++i)
                {
                    xi = positions[i][0];
                    yi = positions[i][1];
                    dis += (x0-xi)*(x0-xi)+(y0-yi)*(y0-yi);
                }
            }
        }
        return sqrt(*d.begin());
    }
};
void printv(vector<int>& v)
{
    for(auto& vi : v)
        cout << vi << " ";
    cout << endl;
}
int main() {
    vector<vector<int>> v6 ={{1,1},{3,3}};
    vector<vector<int>> v5 ={{0,1},{1,2},{0,2}};
    vector<double> v1 = {0.5,0.5,0.2};
    vector<int> v2 = {1,1,1,9,7};
    vector<int> v3 = {332484035, 524908576, 855865114, 632922376, 222257295, 690155293, 112677673, 679580077, 337406589, 290818316, 877337160, 901728858, 679284947, 688210097, 692137887, 718203285, 629455728, 941802184};
    vector<int> v4 = {1,3,2};
    string str = "eceeeefasdghjklqwertyuio";
    vector<vector<string>> st  = {{"A","B"},{"C"},{"B","C"},{"D"}};

    vector<string> st1 = {"like","god","internal","me","internet","interval","intension","face","intrusion"};
    Solution s;
//    s.maxProbability(3,v5,v1,0,2);
    s.getMinDistSum(v6);
    string s1 = "1";
    cout << s1[1] << "s[1]" << endl;
    TreeNode *t1 = new TreeNode(1);
    TreeNode *t2 = new TreeNode(2);
    TreeNode *t3 = new TreeNode(3);
    TreeNode *t4 = new TreeNode(4);
    TreeNode *t5 = new TreeNode(5);
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