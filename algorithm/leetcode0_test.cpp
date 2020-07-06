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
    int countUni()
    {
        int count = 0;
        for(int i = 0; i < f.size(); ++i)
        {
            if(i == find(i))
                count++;
        }
        return count;
    }
};
class Solution {
public:
    int maxA(int N) {
        vector<set<pair<int,int>>> dp(N+1);
        //dp[i] 表示，按了 i 次按键，得到的字符 和 缓存字符数量
        dp[1].insert({1, 0});//按一次A,能出来一个A, 缓存里没有数据
        int i, j;
        for(j = 2; j <= N; ++j)
        {	// j 是下一个要到达的状态
            // ACV,6下按键，字符翻倍, 缓存更新
            // V, 2下按键，粘贴前一次的数量，缓存不变
            // A, 1下按键
            //
            if(j-1 >= 1 && !dp[j-1].empty())//前面状态存在，按一下按键A
            {
                for(auto it = dp[j-1].begin(); it != dp[j-1].end(); ++it)
                {
                    dp[j].insert({it->first+1, it->second});
                }
            }
            if(j-2 >= 1 && !dp[j-2].empty())//前面状态存在，按2下按键,粘贴
            {
                for(auto it = dp[j-2].begin(); it != dp[j-2].end(); ++it)
                {
                    dp[j].insert({it->first+it->second, it->second});
                }
            }
            if(j-6 >= 1 && !dp[j-6].empty())//前面状态存在，按6下按键,复制粘贴
            {
                for(auto it = dp[j-6].begin(); it != dp[j-6].end(); ++it)
                {
                    dp[j].insert({it->first*2, it->first});
                }
            }
        }
        return dp[N].rbegin()->first;
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
    vector<vector<int>> v5 ={{0, 1}, {0, 2}, {2, 3}, {2, 4}};
    vector<int> v1 = {113, 215, 221};
    vector<int> v2 = {5,4,0,3,1,6,2};
    vector<int> v3 = {332484035, 524908576, 855865114, 632922376, 222257295, 690155293, 112677673, 679580077, 337406589, 290818316, 877337160, 901728858, 679284947, 688210097, 692137887, 718203285, 629455728, 941802184};
    vector<int> v4 = {1,3,2};
    string str = "eceeeefasdghjklqwertyuio";
    vector<vector<string>> st  = {{"A","B"},{"C"},{"B","C"},{"D"}};

    vector<string> st1 = {"like","god","internal","me","internet","interval","intension","face","intrusion"};
    Solution s;
//

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
    s.maxA(7);

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