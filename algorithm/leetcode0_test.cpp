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
class MaxStack {
    int maxelem = INT_MIN;
    stack<int> s;
    stack<int> temp;
    int v, m;
public:
    /** initialize your data structure here. */
    MaxStack() {

    }

    void push(int x) {
        maxelem = max(maxelem, x);
        s.push(x);
        s.push(maxelem);
    }

    int pop() {
        s.pop();
        v = s.top();
        s.pop();
        return v;
    }

    int top() {
        m = s.top();
        s.pop();
        v = s.top();
        s.push(m);
        return v;
    }

    int peekMax() {
        return s.top();
    }

    int popMax() {
        int ans = s.top();
        maxelem = s.top();
        bool flag = true;
        while(flag)
        {
            s.pop();
            if(s.top() != maxelem)
                temp.push(s.top());
            else
                flag = false;
            s.pop();
        }
        maxelem = s.empty() ? INT_MIN : s.top();
        while(!temp.empty())
        {
            v = temp.top();
            temp.pop();
            s.push(v);
            maxelem = max(maxelem, v);
            s.push(maxelem);
        }
        return ans;
    }
};
void printv(vector<int>& v)
{
    for(auto& vi : v)
        cout << vi << " ";
    cout << endl;
}
int main() {
    vector<vector<int>> v6 ={{0,1},{1,1}};
    vector<vector<int>> v5 ={{1,1},{1,0}};
    vector<int> v1 = {2,1};
    vector<int> v2 = {5,4,0,3,1,6,2};
    vector<int> v3 = {332484035, 524908576, 855865114, 632922376, 222257295, 690155293, 112677673, 679580077, 337406589, 290818316, 877337160, 901728858, 679284947, 688210097, 692137887, 718203285, 629455728, 941802184};
    vector<int> v4 = {1,3,2};
    string str = "eceeeefasdghjklqwertyuio";
    vector<vector<string>> st  = {{"A","B"},{"C"},{"B","C"},{"D"}};

    vector<string> st1 = {"ab","bc"};
//    Solution s;
//

    string s1 = "1";
    cout << s1[1] << "s[1]" << endl;
    TreeNode *t1 = new TreeNode(1);
    TreeNode *t2 = new TreeNode(2);
    TreeNode *t3 = new TreeNode(3);
    TreeNode *t4 = new TreeNode(3);
    TreeNode *t5 = new TreeNode(4);
    t1->left = t2;
    t1->right = t3;
//    t2->left = t4;
//    t2->right = t5;
//    s.boldWords(st1,"aabcd");
    MaxStack s;
    s.push(74);
    s.popMax();
    s.push(89);
    s.push(67);
    s.popMax();
    s.pop();
    s.push(61);
    s.push(-77);
    s.peekMax();
    s.popMax();
    s.push(81);
    s.pop();
    s.push(-71);
    s.push(32);
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