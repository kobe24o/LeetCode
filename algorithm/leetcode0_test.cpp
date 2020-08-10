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
    int maxVacationDays(vector<vector<int>>& flights, vector<vector<int>>& days) {
        int dp[101][101];// 在 i 城市时， 是第 k 周， 最多休假天数
        memset(dp, -1, sizeof(dp));
        unordered_map<int,unordered_set<int>> g;
        for(int i = 0; i < flights.size(); ++i)
        {
            g[i].insert(i);//可以待在原地不走
            for(int j = 0; j < flights[i].size(); ++j)
                if(flights[i][j])
                    g[i].insert(j);
        }//建图
        int n = flights.size(), k = days.size(), maxdays = 0;
        for(int i = 0; i < n; ++i)//初始化第0周
        {
            if(g[0].count(i))//0城市可以飞到i城市
            {
                dp[i][0] = days[i][0];
                maxdays = max(maxdays, dp[i][0]);
            }
        }
        for(int wk = 1; wk < k; ++wk)//遍历剩余的周
        {
            for(int i = 0; i < n; ++i)//遍历每个城市
            {
                if(dp[i][wk-1] == -1)//上周i城市的状态不存在
                    continue;
                for(int j = 0; j < n; ++j)//我要去 j 城市
                {
                    if(!g[i].count(j))//没有航班，不行
                        continue;
                    dp[j][wk] = max(dp[j][wk], dp[i][wk-1]+days[j][wk]);
                    maxdays = max(maxdays, dp[j][wk]);
                }
            }
        }
        return maxdays;
    }
};
void printv(vector<int>& v)
{
    for(auto& vi : v)
        cout << vi << " ";
    cout << endl;
}
int main() {
    vector<vector<int>> v6 ={{0,0,0},{0,0,0},{0,0,0}};
    vector<vector<int>> v5 ={{1,1,1},{7,7,7},{7,7,7}};
    vector<double> v1 = {0.5,0.5,0.2};
    vector<int> v2 = {1,3,4,5};
    vector<int> v3 = {332484035, 524908576, 855865114, 632922376, 222257295, 690155293, 112677673, 679580077, 337406589, 290818316, 877337160, 901728858, 679284947, 688210097, 692137887, 718203285, 629455728, 941802184};
    vector<int> v4 = {1,3,2};
    string str = "eceeeefasdghjklqwertyuio";
    vector<vector<string>> st  = {{"A","B"},{"C"},{"B","C"},{"D"}};
    vector<string> st1 = {"0.700","2.800","4.900"};

    Solution s;
    s.maxVacationDays(v6,v5);



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