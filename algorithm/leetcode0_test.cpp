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
class dsu1
{
public:
    vector<int> f;
    dsu1(int n)
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

class dsu
{
public:
    unordered_map<string,string> f;
    dsu(vector<vector<string>>& accounts)
    {
        for(int i = 0; i < accounts.size(); ++i)
        {
            for(int j = 1; j < accounts[i].size(); ++j)
            {
                if(!f.count(accounts[i][j]))
                    f[accounts[i][j]] = accounts[i][1];
                    //以第一个邮件作为代表
                else
                    f[f[accounts[i][j]]] = accounts[i][1];
            }
        }
    }
    void merge(string& a, string& b)
    {
        string fa = find(a), fb = find(b);
        f[fa] = fb;
    }
    string find(string &a)
    {
        if(f[a] == a)
            return a;
        return f[a] = find(f[a]);
    }
};
class Solution {
public:
    string decodeAtIndex(string S, int K) {
        int encode_len = 0, i;
        string encstr, temp;
        K--;
        for(i = 0; i < S.size(); i++)
        {
            if(isalpha(S[i]))
            {
                encstr += S[i];
                encode_len++;
                if(encode_len == K+1)
                    return string(1,encstr[K]);
            }
            else
            {
                if(encode_len*(S[i]-'0') >= K)
                    return string(1,encstr[K%encode_len]);
                else
                {
                    encode_len *= (S[i]-'0');
                    int n = (S[i]-'0')-1;
                    temp = encstr;
                    while(n--)
                        temp += encstr;
                    encstr = temp;
                }
            }
        }
        return "";
    }
};
void printv(vector<int>& v)
{
    for(auto& vi : v)
        cout << vi << " ";
    cout << endl;
}
int main() {
    vector<vector<char>> v6 ={{'d','b','b'},{'c','a','a'},{'b','a','c'},{'c','c','c'},{'d','d','a'}};
    vector<vector<string>> v5 = {{"Alex","Alex5@m.co","Alex4@m.co","Alex0@m.co"},{"Ethan","Ethan3@m.co","Ethan3@m.co","Ethan0@m.co"},{"Kevin","Kevin4@m.co","Kevin2@m.co","Kevin2@m.co"},{"Gabe","Gabe0@m.co","Gabe3@m.co","Gabe2@m.co"},{"Gabe","Gabe3@m.co","Gabe4@m.co","Gabe2@m.co"}};
    vector<double> v1 = {0.5,0.5,0.2};
    vector<int> v2 = {6,2,4};
    vector<int> v3 = {332484035, 524908576, 855865114, 632922376, 222257295, 690155293, 112677673, 679580077, 337406589, 290818316, 877337160, 901728858, 679284947, 688210097, 692137887, 718203285, 629455728, 941802184};
    vector<int> v4 = {1,3,2};
    string str = "a2b3c4d5e6f7g8h9";
    vector<vector<string>> st  = {{"A","B"},{"C"},{"B","C"},{"D"}};
    vector<string> st1 = {"0.700","2.800","4.900"};
    TreeNode* r1 = new TreeNode(0);
    TreeNode* r2 = new TreeNode(0);
    TreeNode* r3 = new TreeNode(0);
    TreeNode* r4 = new TreeNode(0);
    r1->left = r2;
    r2->left = r3;
    r2->right = r4;
    Solution s;
    s.decodeAtIndex(str,3);



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

    return 0;
}